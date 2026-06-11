#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using ll = long long;
#define fast_io(); std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

int main(){
    int n; std::cin >> n;
    std::vector<std::vector<std::pair<int, bool>>> xy(n);
    rep(i,n){
        int ai; std::cin >> ai;
        std::vector<std::pair<int, bool>> xyi;
        rep(j,ai){
            int xi; bool yi;
            std::cin >> xi >> yi; xi--;
            xyi.push_back(std::make_pair(xi,yi));
        }
        xy[i] = xyi;
    }

    int ans = 0;
    for(int bits=0; bits<(1<<n); bits++){
        bool flag = true;
        for(int i=0; i<n; i++){
            for(auto xyi:xy[i]){
                int x = xyi.first;
                bool y = xyi.second;
                if(bits&(1<<i)){
                    if(y && !(bits&(1<<x))) flag=false;
                    if(!y && (bits&(1<<x))) flag=false;
                }
            }
        }

        if(flag==true){
            int cnt = 0;
            for(int i=0; i<n; i++){
                if(bits&(1<<i)) cnt++;
            }
            ans = std::max(ans, cnt);
        }
    }
    std::cout << ans << "\n";
    return 0;
}
