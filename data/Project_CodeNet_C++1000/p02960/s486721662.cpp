#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(i = 0;i < n;++i)
#define all(v) v.begin(), v.end()
using ll = long long;

int main()
{
    ll i,j;
    string s;
    cin >> s;
    const ll MOD = 1e9+7;
    ll n = s.size();
    vector<vector<ll>> dp(n,vector<ll>(13,0));
    vector<ll> spare(n);
    spare.at(0) = 1;
    if(s.at(n-1) != '?'){
        ll now = s.at(n-1)-'0';
        ++dp.at(0).at(now);
    }else{
        for(i = 0;i < 10;++i){
            dp.at(0).at(i)++;
        }
    }
    for(i = 1;i < n;++i){
        spare.at(i) = spare.at(i-1)*10%13;
        if(s.at(n-1-i) != '?'){
            ll now = s.at(n-1-i) - '0';
            ll sp = now*spare.at(i)%13;
            rep(j,13){
                dp.at(i).at(j) += dp.at(i-1).at((j + 13 - sp)%13);
                dp.at(i).at(j) %= MOD;
            }
        }else{
            rep(j,10){
                ll sp = j*spare.at(i)%13;
                ll l;
                rep(l,13){
                    dp.at(i).at(l) += dp.at(i-1).at((l + 13 - sp)%13);
                    dp.at(i).at(l) %= MOD;
                }
            }
        }
    }
    cout << dp.at(n-1).at(5) << endl;
    return 0;
}