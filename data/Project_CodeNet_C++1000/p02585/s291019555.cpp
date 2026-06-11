#include<iostream>
#include<vector>

#define MAX_N 5001
#define rep(i,n) for(int i=0;i<(n);++i)
#define ll long long


int main(){
    int n,k; std::cin>> n >> k;
    int C[MAX_N], P[MAX_N];
    ll ans=-1e18;
    rep(i,n) std::cin >> P[i];
    rep(i,n) std::cin >> C[i];
    rep(i,n) --P[i];

    rep(i,n){
        int x=i;
        std::vector<int> lp;
        ll total=0;
        while(1){
            x = P[x];
            lp.push_back(C[x]);
            total += C[x];
            if(x == i) break;
        }
        int L=lp.size();
        ll t=0;
        rep(j,L){
            t += lp[j];
            if(j+1 > k) break;
            ll now=t;
            if(total > 0){
                ll e = (k-(j+1))/L;
                now += total*e;
            }
            ans = std::max(ans, now);
        }
    }
    std::cout << ans << std::endl;

    return 0;
}
