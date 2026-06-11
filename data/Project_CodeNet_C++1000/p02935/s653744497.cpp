#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < (n); ++i)
#define ll long long
const ll mod = 1e9+7;
const ll INF = 1e18;
const double pi = acos(-1);


int main(void)
{
    ll n; cin>>n;
    vector<ll> a(n);
    rep(i,n) cin>>a[i];
    sort(a.begin(),a.end());
    double ans=a[0];
    for(int i=1;i<n;i++){
        ans+=a[i];
        ans/=2.0;
    }
    cout<<ans<<endl;
    return 0;
}
