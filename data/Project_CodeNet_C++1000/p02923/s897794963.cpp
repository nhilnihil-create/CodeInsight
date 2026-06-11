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
    int n; std::cin >> n;
    std::vector<int> h(n);
    for(int i=0; i<n; i++){
        std::cin >> h[i];
    }

    int ans = 0, cnt = 0;
    for(int i=0; i<n-1; i++){
        if(h[i]>=h[i+1]){
            cnt++;
        }else{
            ans = std::max(cnt,ans);
            cnt = 0;
        }
    }
    ans = std::max(cnt, ans);

    std::cout << ans << "\n";
    return 0;
}
