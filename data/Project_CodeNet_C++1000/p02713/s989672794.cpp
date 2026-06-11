#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <chrono>

#define ll long long

// 2つの値の最大公約数を求める
int gcd(int a, int b) {
    if(b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

// 3つの最大公約数を求める
int GCD(int a, int b, int c) {
    int tmp = gcd(a, b);
    return gcd(tmp, c);
}

int main()
{
    int K;
    std::cin >> K;

    ll sum = 0;
    
    for(int i=1; i <= K; i++) {
        for(int j=1; j <= K; j++) {
            for(int k = 1; k <= K; k++) {
                sum += GCD(i, j, k);
            }
        }
    }

    std::cout << sum << std::endl;
}