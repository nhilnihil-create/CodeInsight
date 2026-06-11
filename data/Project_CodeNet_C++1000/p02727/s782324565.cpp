#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (ll i=0;i<(n);i++)
#define REP(i,n) for (ll i=1;i<=(n);i++)
typedef long long ll;

int main() {
    ll x,y,a,b,c;
    cin >> x >> y >> a >> b >> c;
    vector<ll> p(a),q(b),r(c);
    rep(i,a) cin >> p[i];
    rep(i,b) cin >> q[i];
    rep(i,c) cin >> r[i];
    sort(p.rbegin(),p.rend()); sort(q.rbegin(),q.rend()); sort(r.rbegin(),r.rend());
    ll ans = 0;
    rep(i,x) ans+=p[i];
    rep(i,y) ans+=q[i];
    ll z = 0;
    while(1){
        if(x==0&&y==0){
            break;
        }else if(x==0){
            if(q[y-1]<r[z]){
                ans-=q[y-1]; ans+=r[z];
                y--; z++;
                continue;
            }else{
                break;
            }
        }else if(y==0){
            if(p[x-1]<r[z]){
                ans-=p[x-1]; ans+=r[z];
                x--; z++;
                continue;
            }else{
                break;
            }
        }
        if(z==c) break;
        if(p[x-1]>=q[y-1]){
            if(q[y-1]<r[z]){
                ans-=q[y-1]; ans+=r[z];
                y--; z++;
            }else{
                break;
            }
        }else{
            if(p[x-1]<r[z]){
                ans-=p[x-1]; ans+=r[z];
                x--; z++;
            }else{
                break;
            }
        }
    }
    cout << ans << endl;
}