#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define ve vector
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)

int main(){
    ll n,k;
    cin >> n >> k;
    ve<ll> c(n), p(n);
    rep(i,n){
        cin >> p[i];
        p[i]--;
    }
    rep(i,n) cin >> c[i];
    ve<bool> check(n,false);
    
    ll ans=-1e13;
    
    rep(i,n){
        if(check[i]) continue;
        ve<ll> c1;
        check[i] = true;
        c1.push_back(c[i]);
        ll x = i;
        while(!check[p[x]]){
            check[p[x]] = true;
            c1.push_back(c[p[x]]);
            x = p[x];
        }
        ll nc = c1.size();
        c1.insert(c1.end(), c1.begin(), c1.end());
        
        ve<ll> ruiseki(2*nc+1);
        ruiseki[0] = 0;
        rep(j,2*nc)ruiseki[j+1] = ruiseki[j] + c1[j];
        if(nc>k){
            rep(p,nc){
                rep(q,k){
                    chmax(ans,ruiseki[p+q+1]-ruiseki[p]);
                }
            }
        }else{
            if(ruiseki[nc]<=0){
                rep(p,nc){
                    rep(q,nc){
                        chmax(ans,ruiseki[p+q+1]-ruiseki[p]);
                    }
                }
            }else{
                ll memo = k/nc;
                memo *= ruiseki[nc];
                ll amari = k%nc;
                if (amari==0) {
                    amari = nc;
                    memo -= ruiseki[nc];
                }
                rep(p,nc){
                    rep(q,amari){
                        chmax(ans, ruiseki[p+q+1]-ruiseki[p]+memo);
                    }
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
