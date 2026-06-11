#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < (n); ++i)
#define ll long long
const ll MOD = 1e9+7;
const ll INF = 1e18;
const double pi = acos(-1);

int main(void)
{
    ll n; cin>>n;
    vector<string> s(n);
    map<string,ll> mp;
    rep(i,n){
        cin>>s[i];
        mp[s[i]]++;
    }
    ll ans=0;
    for(auto x:mp){
        if(mp.size()>0) ans++;
    }
    cout<<ans<<endl;
    return 0;
}