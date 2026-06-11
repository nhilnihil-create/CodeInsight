#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define rep2(i,m,n) for(int (i)=(m);(i)<(n);(i)++)
ll MOD = 1e9+7;
ll INF = 1LL<<60;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
	ll n; cin>>n;
    vector<ll> x(n),y(n);
    rep(i,n)cin>>x[i]>>y[i];
    ll ans = n;
    rep(i,n-1){
        rep2(j,i+1,n){
            ll p=x[i]-x[j];
            ll q=y[i]-y[j];
            ll a = n;
            rep(k,n){
                rep(l,n){
                    if(x[k]-x[l]==p&&y[k]-y[l]==q)a--;
                }
            }
            ans=min(ans,a);

        }
    }
    cout<<ans<<endl;
	return 0;
}