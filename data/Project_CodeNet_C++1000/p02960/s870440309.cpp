#include <bits/stdc++.h>
 
#define rep(i,n) for(ll i=0;i<n;++i)
#define all_map(pos,mp) for(ll pos=mp.begin();pos!=mp.end();pos -++)
#define ALL(a) (a).begin(),(a).end()

using namespace std;
using ll  = long long;
using pll = pair<ll, ll>;

const ll MOD  = 1e9 + 7;
const ll LINF = 1LL << 62;
const int INF = 1e9 + 7;

int main(){
    string s;
    cin >> s;

    // dp[i][j] : 上位i桁で，あまりがjである個数
    ll dp[s.size()+1][13] = {};
    dp[0][0] = 1;

    rep(i, s.size()){
        if(s[i] == '?'){
            rep(j, 13){
                rep(k, 10){
                    dp[i+1][(j*10+k) % 13] += dp[i][j];
                    dp[i+1][(j*10+k) % 13] %= MOD;
                }
            }
        }
        else {
            ll digit = s[i] - '0';
            rep(j, 13){
                dp[i+1][(j*10+digit) % 13] += dp[i][j];
                dp[i+1][(j*10+digit) % 13] %= MOD;
            }
        }
    }

    cout << dp[s.size()][5] << endl;
}