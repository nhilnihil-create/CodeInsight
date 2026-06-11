#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (ll i=0; i < (ll)(n); i++)

int main(){
    int n;
    cin>>n;
    vector<ll> x(n),y(n);
    rep(i,n)cin>>x[i]>>y[i];

    vector<ll> a(n),b(n);

    ll a_max=-1e11,b_max=-1e11,a_min=1e11,b_min=1e11;

    rep(i,n){
        a[i]=x[i]+y[i];
        b[i]=x[i]-y[i];
        a_max=max(a_max,a[i]);
        b_max=max(b_max,b[i]);
        a_min=min(a_min,a[i]);
        b_min=min(b_min,b[i]);
    }
    ll ans=max(a_max-a_min,b_max-b_min);
    cout<<ans<<endl;
}