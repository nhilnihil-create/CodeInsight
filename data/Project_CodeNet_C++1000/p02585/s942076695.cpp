#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (ll i=0;i<(n);i++)
#define REP(i,n) for (ll i=1;i<=(n);i++)
typedef long long ll;

int main() {
    ll n,k;
    cin >> n >> k;
    vector<ll> p(n+1),c(n+1);
    REP(i,n) cin >> p[i];
    REP(i,n) cin >> c[i];
    ll ans = -10000000000;
    REP(i,n){
        ll now = 0;
        ll place = i;
        bool unloop = true;
        REP(j,k){
            if(unloop){
                place=p[place];
                now+=c[place];
                ans = max(ans,now);
                if(place==i){
                    now*=(k/j-1);
                    REP(t,k%j+j){
                        place=p[place];
                        now+=c[place];
                        ans=max(ans,now);
                    }
                    unloop = false;
                }
            }
        }
        //cout << i << " " << place << " " << now << endl;
        ans = max(ans,now);
    }
    cout << ans << endl;
}