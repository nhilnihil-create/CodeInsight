#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <numeric>
#include <cstdint>
#include <iomanip>
using ll = long long;
#define fast_io(); std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

int main(){
    std::string s; std::cin >> s;

    std::vector<ll> v(s.size()+1,0);
    for(ll i=0; i<v.size(); i++){
        if(s[i]=='<') v[i+1] = v[i] + 1;
    }
    for(ll i=v.size()-1; i>=0; i--){
        if(s[i]=='>') v[i] = std::max(v[i], v[i+1]+1);
    }
    std::cout << std::accumulate(v.begin(),v.end(),0LL) << "\n";
    return 0;
}
