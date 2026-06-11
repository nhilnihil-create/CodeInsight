#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

#define ll long long

int main()
{
    ll N, M;
    std::cin >> N >> M;

    std::vector<ll> A(M);
    for(ll i=0; i < M; i++) {
        std::cin >> A[i];
    }

    ll sum = 0;
    for(ll i=0; i < M; i++) {
        sum += A[i];
    }

    ll ans = N - sum;
    if(ans < 0) {
        std::cout << "-1" << std::endl;
    }
    else {
        std::cout << ans << std::endl;
    }
}