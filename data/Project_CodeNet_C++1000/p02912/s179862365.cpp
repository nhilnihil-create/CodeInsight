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
#include <queue>
#define rep(i,n) for(int i=0; i<(n); i++)
using ll = long long;
#define fast_io(); std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

int main(){
    int n,m;
    std::cin >> n >> m;
    std::priority_queue<ll> a;
    rep(i,n){
        ll ai; std::cin >> ai;
        a.push(ai);
    }

    rep(i,m){
        int max_a = a.top();
        a.pop();
        a.push(max_a/2);
    }

    ll ans = 0;
    while(!a.empty()){
        ans += a.top();
        a.pop();
    }
    std::cout << ans << "\n";
    return 0;
}
