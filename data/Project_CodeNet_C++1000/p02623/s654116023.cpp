#include <bits/stdc++.h>
using ll = long long;
using namespace std;
ll GCD(ll a, ll b){ return a ? GCD(b % a, a) : b; }
int main(){
    ll n,m,k;
    cin>>n>>m>>k;
    vector<ll> a(n),b(m),suma(n+1),sumb(m+1);
    for(auto &i:a) cin>>i;
    for(auto &i:b) cin>>i;
    suma[0]=0;
    sumb[0]=0;
    ll ans = 0;
    for(int i=0; i<n; i++) suma[i+1] = suma[i] + a[i];
    for(int i=0; i<m; i++) sumb[i+1] = sumb[i] + b[i];
    for(ll i=0; i<=n; i++){
        ll tmp = k - suma[i];
        if(tmp < 0) break;
        auto border = upper_bound(sumb.begin(), sumb.end(), tmp);
        ans = max(i+(border-sumb.begin())-1,ans);
    }
    cout<<ans<<endl;

}