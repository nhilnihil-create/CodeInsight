#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <bitset>

#define ll long long

int main()
{
    ll N;
    std::cin >> N;

    std::map<ll, ll> mp;
    for(ll i=2; i*i <= N; i++) {
        if(N%i==0) {
            mp[i]++;
            N/=i;
            i--;
        }
    }

    if(N != 1) {
        mp[N]++;
    }

    ll ans =0 ;
    for(auto itr=mp.begin(); itr!=mp.end(); itr++) {
        //std::cout << itr->first << ", " << itr->second << std::endl;
        for(int i=1; itr->second>=i; i++) {
            //std::cout << itr->second << ", " << i << std::endl;
            ans++;
            itr->second -= i;
        }
        //std::cout << std::endl;
    }
    std::cout << ans << std::endl;
}