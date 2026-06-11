#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <vector>

#define ll long long

int main()
{
    ll K, N;
    std::cin >> K >> N;

    std::vector<ll> A(N);
    for(ll i=0; i < N; i++) {
        std::cin >> A[i];
    }

    ll max_len = 0;
    for(ll i=1; i < N; i++) {
        max_len = max_len > (A[i]-A[i-1]) ? max_len : (A[i]-A[i-1]);
    }
    max_len = max_len > (K - A[N-1] + A[0]) ? max_len : (K-A[N-1]+A[0]);
    std::cout << K - max_len << std::endl;
}