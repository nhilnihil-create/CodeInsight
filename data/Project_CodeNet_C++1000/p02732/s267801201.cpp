#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <vector>

#define ll long long

ll Sum(ll x) {
    return x * (x-1) / 2;
}

int main()
{
    ll N;
    std::cin >> N;

    std::vector<ll> A(N);
    std::map<ll, ll> mp;
    for(ll i=0; i < N; i++) {
        ll x;
        std::cin >> x;
        A[i] = x;
        mp[x]++;
    }

    std::map<ll, ll> result;
    
    ll sum = 0;
    for(auto p : mp) {
        ll num = p.second;
        sum += Sum(num);
    }

    for(auto p : mp) {
        ll a1 = p.first;
        ll a2 = p.second;

        result[a1] = sum + Sum(a2-1) - Sum(a2);
    }

    for(ll i=0; i < N; i++) {
        std::cout << result[A[i]] << std::endl;
    }
}