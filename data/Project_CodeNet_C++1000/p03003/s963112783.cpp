#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(i = 0;i < n;++i)
#define all(v) v.begin(), v.end()
using ll = long long;

ll pow_mod(ll a, ll n, ll p)
{
    ll res = 1;
    while(n > 0){
        if(n & 1) res = res*a%p;
        a = a*a%p;
        n >>= 1;
    }
    return res;
}

int main()
{
    ll i,j;
    ll n,m;
    cin >> n >> m;
    const ll MOD = 1e9+7;
    vector<ll> s(n);
    vector<ll> t(m);
    for(i = 0;i < n;++i){
        cin >> s.at(i);
    }
    for(i = 0;i < m;++i){
        cin >> t.at(i);
    }
    vector<vector<ll>> dp(n+1,vector<ll>(m+1,0));
    vector<vector<ll>> sdp(n+1,vector<ll>(m+1,0));
    dp.at(0).at(0) = 1;
    sdp.at(0).at(0) = 1;
    for(i = 0;i <= n;++i){
        for(j = 0;j <= m;++j){
            if(i == 0 && j == 0) continue;
            if(i == 0){
                sdp.at(i).at(j) = sdp.at(i).at(j-1);
                continue;
            }else if(j == 0){
                sdp.at(i).at(j) = sdp.at(i-1).at(j);
                continue;
            }
            if(s.at(i-1) == t.at(j-1)){
                dp.at(i).at(j) = sdp.at(i-1).at(j-1);
            }
            sdp.at(i).at(j) = sdp.at(i).at(j-1) + sdp.at(i-1).at(j) + MOD - sdp.at(i-1).at(j-1) + dp.at(i).at(j);
            sdp.at(i).at(j) %= MOD;
        }
    }
    cout << sdp.at(n).at(m) << endl;
    return 0;
}