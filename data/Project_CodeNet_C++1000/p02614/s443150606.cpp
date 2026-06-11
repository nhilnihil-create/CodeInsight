#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define REP(i,x,n) for(int i = (x); i < (n); ++i)
#define ll long long
#define P pair<ll,ll>
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()

const ll mod = 1e9+7;
const ll INF = 1e18;
const double pi = acos(-1);

int main(void)
{
    ll h,w,k,ans=0;
    cin>>h>>w>>k;
    vector<string> c(h);
    rep(i,h) cin>>c[i];
    rep(biti,(1<<h))rep(bitj,(1<<w)){
        ll cnt=0;
        rep(i,h)rep(j,w){
            if(biti & (1<<i)) continue;
            if(bitj & (1<<j)) continue;
            if(c[i][j]=='#') cnt++;
        }
        if(cnt==k) ans++;
    }
    cout << ans << endl;
    return 0;
}