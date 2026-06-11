#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
#define REP(i, n) for(int i = 0; i <= n; i++)
#define ll long long
using namespace std;

int keta(int n) {
    int res;
    for(int i = 0; i < 100; i++) {
        n = n / 10;

        if(n == 0) {
            res = i + 1;
            break;
        }
    }
    return res;
}

signed main(){
    ll n,d;cin>>n>>d;
    ll ans=0;
    rep(i,n){
        ll x,y;cin>>x>>y;
        if(x*x+y*y<=d*d) ans++;
    }
    cout<<ans<<endl;
    return 0;
}