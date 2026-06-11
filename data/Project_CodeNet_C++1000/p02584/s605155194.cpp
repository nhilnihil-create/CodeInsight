#include <iostream>

const int maxn = 1e2 + 5;
long long seq[maxn];
inline long long abs(long long x) {return x > 0 ? x : -x;}
inline long long min(long long x, long long y) {return x > y ? x : y;} 
int main(){
    long long x, k, d;
    std::cin >> x >> k >> d;
    long long tm = abs(x) / d;
    if (tm >= k ) {
        std::cout << (x > 0 ? abs(x - k * d): abs(x + k * d)) << std::endl;
    }else {
        if ((k - tm) & 1) {
            if (x > 0) {
                std::cout << abs(x - tm * d - d) << std::endl;
            }else {
                std::cout << abs(x + tm * d + d) << std::endl; 
            }
        }else {
            std::cout << (x > 0 ? abs(x - tm * d): abs(x + tm * d)) << std::endl;
        }
    }
}