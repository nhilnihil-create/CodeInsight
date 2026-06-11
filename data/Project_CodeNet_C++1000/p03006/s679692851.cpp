#include<bits/stdc++.h>
using ll = long long;
using P = std::pair<ll,ll>;

int main(){
        ll n;
        scanf("%lld", &n);

        ll mn = 1e18;
        std::vector<P> pt(n);
        for(ll i=0; i<n; i++) scanf("%lld %lld", &pt[i].first, &pt[i].second);

        ll size = 0;
        std::vector<P> pp(n*(n+1)/2);
        for(ll i=0; i<n-1; i++) for(ll j=i+1; j<n; j++){
                pp[size] = P(pt[i].first-pt[j].first, pt[i].second-pt[j].second);
                size++;
        }


        ll ans = n;
        for(ll i=0; i<size; i++){
                ll cnt = n;
                for(ll j=0; j<size; j++){
                        ll tx, ty, nx, ny;
                        std::tie(tx, ty) = pp[i];
                        std::tie(nx, ny) = pp[j];
                        if(tx==nx&&ty==ny || tx==-nx&&ty==-ny) cnt--;
                }
                ans = std::min(ans, cnt);
        }
        printf("%lld\n", ans);
        return 0;
}