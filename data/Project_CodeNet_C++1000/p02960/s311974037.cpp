#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)
#define VL vector<ll>
#define VS vector<string>
#define VB vector<bool>
#define VP vector<pair<ll,ll>>
#define VVL vector<vector<ll>>
#define VVP vector<vector<pair<ll,ll>>>
#define PL pair<ll,ll>
#define ALL(v) (v).begin(), (v).end()
ll d1[4] = {1, -1, 0, 0};
ll d2[4] = {0, 0, 1, -1};

ll mod = 1e9+7;

ll mod_pow(ll a, ll n, ll mod){
    ll ret = 1;
    while(n > 0){
        if(n & 1) ret = (ret*(a % mod))%mod;
        a = ((a%mod)*(a%mod)) % mod;
        n = n >> 1;
    }
    return ret;
}

ll dp[100010][13];

int main(){
    string S;
    cin >> S;
    ll N = S.size();

    rep(i, 0, N+1){
        rep(j, 0, 13) dp[i][j] = 0;
    }
    dp[0][0] = 1;

    rep(i, 1, N+1){
        ll pw = mod_pow(10, N-i, 13);
        if(S[i-1] == '?'){
            rep(j, 0, 10){
                ll now = (j * pw) % 13;
                rep(k, 0, 13){
                    dp[i][(now + k) % 13] += dp[i-1][k];
                    dp[i][(now + k) % 13] %= mod;
                }
            }
        }else{
            ll now = (pw * (ll)(S[i-1] - '0')) % mod;
            rep(j, 0, 13){
                dp[i][(now + j) % 13] = dp[i-1][j];
            }       
        }
    }

    cout << dp[N][5] << endl;
    return 0;
}