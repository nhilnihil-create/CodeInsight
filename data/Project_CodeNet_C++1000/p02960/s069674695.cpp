#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
using namespace std;
using Graph = vector<vector<int>>;
#define MOD 1000000007ll
#define MOD2 998244353
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long ll;
typedef pair<ll, ll> P;


ll modpow(ll x, ll n){
    ll res = 1;
    ll mul = x;
    while(n){
        if(n % 2) res = res * mul % 13;
        mul = mul * mul % 13;
        n /= 2;
    }
    return res;
}

ll modinv(ll x, ll n){
    return modpow(x, n - 2);
}

ll dp[100010][13];

int main(){
    string s;
    cin >> s;
    // reverse(s.begin(), s.end());
    ll n = s.size();
    dp[0][0] = 1;

    rep(i, n){
        if (s[i] != '?') {
            // ll p = modpow(10, i);
            ll p = (s[i] - '0');
            rep(j, 13){
                dp[i + 1][(j * 10 + p) % 13] += dp[i][j];
            }
        }
        else {
            rep(t, 10){
                // ll p = modpow(10, i);
                rep(j, 13){
                    dp[i + 1][(j * 10 + t) % 13] += dp[i][j];
                }
            }
        }
        rep(j, 13) dp[i + 1][j] %= MOD;
    }

    cout << dp[n][5] << endl;

    return 0;
}