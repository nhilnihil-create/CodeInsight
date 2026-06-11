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
    vector<ll> v(n);
    rep(i,n) cin>>v[i];
    sort(v.begin(),v.end());
    double tmp=v[0];
    for(int i=1;i<n;i++){
        tmp+=v[i];
        tmp/=2;
    }
    cout<<tmp<<endl;
    return 0;
}
