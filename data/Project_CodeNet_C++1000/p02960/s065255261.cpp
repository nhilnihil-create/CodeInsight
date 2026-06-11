#include <bits/stdc++.h>
// #include <atcoder/all>
#define ll long long int
#define ld long double
#define yorn(f) cout<<((f)?"Yes":"No")<<endl;
#define YORN(f) cout<<((f)?"YES":"NO")<<endl;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repi(i, n) for (ll i = 1; i < (ll)(n); i++)
#define all(x) (x).begin(), (x).end()
#define put(x) cout << x << endl;
#define println(x) cout << x << endl;
using namespace std;
// using namespace atcoder;
void Main()
{
    string S;
    cin >> S;

    // dp[n][m]: n+1桁で13で割ったあまりがmである場合
    vector<vector<ll> > dp(S.size(), vector<ll>(13));

    reverse(all(S));

    ll pow10 = 1;
    ll mod = 7LL + 1e9;

    if (S[0] == '?') {
        rep(k, 10) {
            dp[0][k] = 1;
        }
    }
    else {
        dp[0][S[0] - '0'] = 1;
    }

    repi(i, S.size()) {
        pow10 *= 10;
        pow10 %= 13;
        if (S[i] != '?') {
            ll a = (pow10 * (S[i] - '0')) % 13;
            rep(j, 13) {
                ll b = (j + a) % 13;
                dp[i][b] += dp[i-1][j];
                dp[i][b] %= mod;
            }
        }
        else {
            rep(k, 10) {
                ll a = pow10 * k % 13;
                rep(j, 13) {
                    ll b = (j + a) % 13;
                    dp[i][b] += dp[i-1][j];
                    dp[i][b] %= mod;
                }
            }
        }
    }

    ll res = 0;
    put(dp[S.size() - 1][5]);
}
signed main(){ Main();return 0;}