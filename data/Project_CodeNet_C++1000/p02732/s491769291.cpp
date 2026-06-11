#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <numeric>
#include <cstdint>
#include <iomanip>
#include <set>
using ll = long long;
#define fast_io(); std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

int main(){
    fast_io();

    ll n; std::cin>>n;
    std::vector<ll> a(n), v(200001,0);
    for(ll i=0; i<n; i++){
        std::cin >> a[i]; v[a[i]]++;
    }

    std::set<ll> st(a.begin(),a.end());
    ll c = 0;
    for(auto i : st){
        c += v[i]*(v[i]-1)/2;
    }

    for(ll i=0; i<n; i++){
        std::cout << c - (v[a[i]] - 1) << "\n";
    }
    return 0;
}
