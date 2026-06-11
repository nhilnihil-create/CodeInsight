#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <numeric>
#include <cstdint>
#include <iomanip>
#include <set>
#include <map>
#include <unordered_map>
#include <cassert>
#define rep(i,n) for(int i=0; i<(n); i++)
using ll = long long;
#define fast_io(); std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);


int main(){
    int n, k;
    std::cin >> n >> k;
    std::vector<ll> sum_2e(n+1,0);
    rep(i,n){
        ll pi; std::cin >> pi;
        ll ei = pi+1;
        sum_2e[i+1] = ei + sum_2e[i];
    }

    ll ans = 0;
    for(ll i=0; i+k<n+1; i++){
        ans = std::max(ans, sum_2e[i+k]-sum_2e[i]);
    }

    std::cout << std::fixed << std::setprecision(10) << ans/2.0 << "\n";
    return 0;
}
