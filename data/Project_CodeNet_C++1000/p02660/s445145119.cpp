#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

#include <chrono>

template <typename T>
inline bool is_prime(T n)
{
    if(n <= 1) {
        return false ;
    }

    if(n == 2) {
        return true ;
    }

    if(n % 2 == 0) {
        return false ;
    }

    for(T i = 3 ; i * i <= n ; i += 2) {
        if(n % i == 0) {
            return false ;
        }
    }
    return true ;
}

template <typename T>
inline auto compute_z_list(T n)
{
    std::vector<T> vec ;
    for(T i = 2 ; i * i <= n ; i ++) {
        if(n % i != 0 || !is_prime(i)) {
            continue ;
        }

        auto elem = i ;
        while(n % i == 0) {
            vec.push_back(elem) ;

            if(is_prime(n / elem)) {
                vec.push_back(n / elem) ;
            }

            n /= i ;
            elem *= i ;
        }
    }

    return vec ;
}

template <typename T>
inline size_t func(T num)
{
    static const auto z_list = compute_z_list(num) ;

    static std::vector<T> vec ;
    if(num == 1) return vec.size() ;

    for(auto z : z_list) {
        if(num % z != 0) {
            continue ;
        }

        if(std::find(vec.cbegin(), vec.cend(), z) == vec.cend()) {
            vec.push_back(z) ;
            return func(num / z) ;
        }
    }

    return vec.size() ; //not reached
}


int main()
{
    unsigned long long num ;
    std::cin >> num ;

    if(is_prime(num)) {
        std::cout << 1 << std::endl ;
        return 0 ;
    }

    std::cout << func(num) << std::endl ;
    return 0 ;
}