#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll zero = 0;
const ll INF = 10000000000000000; //10^16
const ll MOD = 1000000007; //10^9+7
const ll MOD2 = 998244353;

int main(){
    string S;
    cin >> S;
    ll L = S.size();
    vector<ll> p = {1,4,3,12,9,10};

    vector<vector<ll>> dp(L+1, vector<ll> (13, 0));
    dp.at(0).at(0) = 1;
    for(ll i = 1; i < 13; i++){
        dp.at(0).at(i) = 0;
    }

    ll cnt = 7 - (L % 6) - 1;
    ll tmp, d;
    for(ll i = 1; i <= L; i++){
        tmp = (cnt + i) % 6;
        if(S.at(i-1) == '?'){
            for(ll j = 0; j < 13; j++){
                for (ll d = 0; d < 10; d++){
                    dp.at(i).at(j) += dp.at(i-1).at( (169+j-p.at(tmp)*d) % 13);        
                }
                dp.at(i).at(j) = dp.at(i).at(j) % MOD;
            }
        }
        else{
            d = (ll)(S.at(i-1) - '0');
            for (ll j = 0; j < 13; j++){
                dp.at(i).at(j) += dp.at(i-1).at( (169+j-p.at(tmp)*d) % 13);
            }
        }
    }
    printf("%lld\n", dp.at(L).at(5));
       
}


