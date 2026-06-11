#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>

#define ll long long

int main()
{
    ll A, B, C, K;
    std::cin >> A >> B >> C >> K;

    ll sum = 0;

    if(K <= A) {
        sum = K;
    }
    else if(K <= A+B) {
        sum = A;
    }
    else {
        sum = A;
        ll tmp = K - (A+B);
        sum  = sum - tmp;
    }

    std::cout << sum << std::endl;
}