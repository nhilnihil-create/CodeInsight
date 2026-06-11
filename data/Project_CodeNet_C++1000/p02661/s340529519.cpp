#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    unsigned int n ;
    std::cin >> n ;

    std::vector<unsigned long> as(n), bs(n) ;
    for(unsigned int i = 0 ; i < n ; i ++) {
        std::cin >> as[i] >> bs[i] ;
    }

    std::sort(as.begin(), as.end()) ;
    std::sort(bs.begin(), bs.end()) ;

    if(n % 2 != 0) {
        //odd (1 step)
        auto am = as[(n + 1) / 2 - 1] ;
        auto bm = bs[(n + 1) / 2 - 1] ;
        std::cout << bm - am + 1 << std::endl ;
    }
    else {
        //even (1 or 0.5 step)
        auto am = (as[n / 2 - 1] + as[n / 2]) ;
        auto bm = (bs[n / 2 - 1] + bs[n / 2]) ;
        std::cout << bm - am + 1 << std::endl ;
    }

    return 0 ;
}