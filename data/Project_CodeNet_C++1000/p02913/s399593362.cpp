#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(i = 0;i < n;++i)
#define all(v) v.begin(), v.end()
using ll = long long;

int main()
{
    ll i,j;
    ll n;
    cin >> n;
    string s;
    cin >> s;
    vector<vector<ll>> dp(n+1,vector<ll>(n+1,0));
    for(i = n-1;i >= 0;--i){
        for(j = n-1;j >= 0;--j){
            if(s.at(i) == s.at(j)) dp.at(i).at(j) = dp.at(i+1).at(j+1) + 1;
        }
    }
    ll ans = 0;
    for(i = 0;i < n;++i){
        rep(j,n){
            ll tmp = min(dp.at(i).at(j), i-j);
            ans = max(ans,tmp);
        }
    }
    cout << ans << endl;
    return 0;
}