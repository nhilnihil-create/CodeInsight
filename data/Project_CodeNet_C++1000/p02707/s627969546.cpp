#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

#define ll long long

int main()
{
    ll N;
    std::cin >> N;

    std::vector<ll> A(N+1);
    std::map<ll, ll> mp;

    for(ll i=2; i <= N; i++) {
        std::cin >> A[i];
    }

    for(ll i=2; i <= N; i++) {
        mp[A[i]]++;
    }

    for(ll i=1; i<= N; i++) {
        std::cout << mp[i] << std::endl;
    }
}