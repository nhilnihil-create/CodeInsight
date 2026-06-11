#include <iostream>
#include <cmath>
#define rep(i,n) for(int i=0; i<(n); ++i)

int main() {
    int n,k; std::cin >> n >> k;
    int digits=0;
    while(n > 0){
        n /= k;
        ++digits;
    }
    std::cout << digits << std::endl;

    return 0;
}
