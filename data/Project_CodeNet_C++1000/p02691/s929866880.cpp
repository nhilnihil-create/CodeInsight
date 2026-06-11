#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i = 0; i < (n); ++i)

int main(){
    ll n; cin>>n;
    vector<ll> a(n);
    map<ll,ll> mp;
    ll ans = 0;
    rep(i,n){
        cin>>a[i];
        ans += mp[i - a[i]];
        mp[i + a[i]]++;
    }
    cout << ans << endl;
    return 0;
}