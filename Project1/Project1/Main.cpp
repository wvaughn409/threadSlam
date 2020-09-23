#include <algorithm>
#include <array>
#include <cstring>
#include <functional>
#include <random>
#include <string>
#include <iostream>
#include <thread> 
#include <sstream> 




template <typename T = std::mt19937>
auto get_random_generator() -> T {
    auto constexpr seed_bytes = sizeof(typename T::result_type) * T::state_size;
    auto constexpr seed_len = seed_bytes / sizeof(std::seed_seq::result_type);
    auto seed = std::array<std::seed_seq::result_type, seed_len>();
    auto dev = std::random_device();
    std::generate_n(begin(seed), seed_len, std::ref(dev));
    auto seed_seq = std::seed_seq(begin(seed), end(seed));
    return T{ seed_seq };
}

void foo()
{

    for (int i = 0; i < 99999; ++i)
    {
        auto str = get_random_generator();
        std::stringstream ss;
        ss << str;
        //std::cout << str;
    }
}

void bar(int x)
{

    for (int i = 0; i < 99999; ++i)
    {
        auto str = get_random_generator();
        std::stringstream ss;
        ss << str;
        //std::cout << str;
    }
} 

int main()
{
    std::thread first(foo);     // spawn new thread that calls foo()
    std::thread second(bar, 0);  // spawn new thread that calls bar(0)
    std::thread third(foo);     // spawn new thread that calls foo()
    std::thread fourth(bar, 0);  // spawn new thread that calls bar(0)
    std::thread fifth(foo);     // spawn new thread that calls foo()
    std::thread sixth(bar, 0);  // spawn new thread that calls bar(0)
    std::thread seventh(foo);     // spawn new thread that calls foo()
    std::thread eighth(bar, 0);  // spawn new thread that calls bar(0)
    std::thread ninth(foo);     // spawn new thread that calls foo()
    std::thread tenth(bar, 0);  // spawn new thread that calls bar(0)
    std::thread eleventh(foo);     // spawn new thread that calls foo()
    std::thread twelfth(bar, 0);  // spawn new thread that calls bar(0)
    std::thread thirteenth(foo);     // spawn new thread that calls foo()
    std::thread fourteenth(bar, 0);  // spawn new thread that calls bar(0)
    std::thread fifteenth(foo);     // spawn new thread that calls foo()
    std::thread sixteenth(bar, 0);  // spawn new thread that calls bar(0)

    //std::cout << "main, foo and bar now execute concurrently...\n";

    // synchronize threads:
    first.join();                // pauses until first finishes
    second.join();               // pauses until second finishes
    third.join();               // pauses until second finishes
    fourth.join();               // pauses until second finishes
    fifth.join();               // pauses until second finishes
    sixth.join();               // pauses until second finishes
    seventh.join();               // pauses until second finishes
    eighth.join();               // pauses until second finishes
    ninth.join();               // pauses until second finishes
    tenth.join();               // pauses until second finishes
    eleventh.join();               // pauses until second finishes
    twelfth.join();               // pauses until second finishes
    thirteenth.join();               // pauses until second finishes
    fourteenth.join();               // pauses until second finishes
    fifteenth.join();               // pauses until second finishes
    sixteenth.join();               // pauses until second finishes

    //std::cout << "foo and bar completed.\n";


    

    /*char ch;

    std::cin >> ch;*/

    return 0;
}