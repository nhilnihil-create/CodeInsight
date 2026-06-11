#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define ll long long
#define P pair<ll,ll>
#define all(v) (v).begin(),(v).end()

const ll mod = 1e9+7;
const ll INF = 1e18;
const double pi = acos(-1.0);

int main(void)
{
    ll n,m,x; cin>>n>>m>>x;
    vector<ll> c(n);
    vector<vector<ll>> a(n,vector<ll>(m));
    rep(i,n){
        cin>>c[i];
        rep(j,m) cin>>a[i][j];
    }
    ll ans=INF;
    rep(bit,(1<<n)){
        ll tmp=0;
        vector<ll> u(m);
        rep(i,n){
            if(bit & (1<<i)){
                tmp+=c[i];
                rep(j,m) u[j]+=a[i][j];
            }
        }
        bool can=true;
        rep(i,m) if(u[i] < x) can=false;
        if(can) ans=min(ans,tmp);
    }
    if(ans==INF) cout<<-1<<endl;
    else cout<<ans<<endl;
    return 0;
}