#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(i = 0;i < n;++i)
#define all(v) v.begin(), v.end()
using ll = long long;

int main()
{
    ll i,j;
    ll n,t;
    cin >> n >> t;
    vector<pair<ll,ll>> ab(n);
    for(i = 0;i < n;++i){
        cin >> ab.at(i).first >> ab.at(i).second;
    }
    sort(all(ab));
    vector<vector<ll>> dp(n+1,vector<ll>(t,0));
    for(i = 1;i <= n;++i){
        rep(j,t){
            if(j < ab.at(i-1).first) dp.at(i).at(j) = dp.at(i-1).at(j);
            else dp.at(i).at(j) = max(dp.at(i-1).at(j), dp.at(i-1).at(j - ab.at(i-1).first) + ab.at(i-1).second);
        }
    }
    ll ans = 0;
    for(i = n-1;i >= 0;--i){
        ans = max(ans, dp.at(i).at(t-1) + ab.at(i).second);
    }
    cout << ans << endl;
    return 0;
}