#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>

#define ll long long

int main()
{
    ll N, A, B;
    std::cin >> N >> A >> B;

    ll sum = A + B;
    ll sho = N / sum;
    ll ans = sho * A;
    ll amari = N % sum;

    if(amari > A) {
        ans += A;
    }
    else {
        ans += amari;
    }

    std::cout << ans << std::endl;
}