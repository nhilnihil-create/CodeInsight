#include <bits/stdc++.h>
using namespace std;
#define repd(i,a,b) for (int i=(a);i<(b);i++)
#define rep(i,n) repd(i,0,n)
#define all(x) (x).begin(),(x).end()
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
typedef long long ll;
const long long INF = 1LL << 60;
const long long MOD = 1e9 + 7;
typedef pair<int, int> P;
int main()
{
    string S;
    cin >> S;

    int len = (int)S.size();
    reverse(all(S));

    vector<vector<ll>> dp(len + 1, vector<ll>(13));
    ll ct = 1;
    dp[0][0] = 1;
    rep(i, len) {
        if (S[i] != '?') {
            ll n = S[i] - '0';
            n *= ct;
            n %= 13;
            rep(k, 13) {
                dp[i + 1][(n + k) % 13] += dp[i][k];
                dp[i + 1][(n + k) % 13] %= MOD;
            }
        }
        else {
            rep(j, 10) {
                ll n = j * ct;
                n %= 13;
                rep(k, 13) {
                    dp[i + 1][(n + k) % 13] += dp[i][k];
                    dp[i + 1][(n + k) % 13] %= MOD;
                }
            }
        }
        ct *= 10;
        ct %= 13;
    }
/*
    rep(i, len + 1) {
        rep(j, 13) cout << dp[i][j] << " ";
        cout << endl;
    }
*/

    cout << dp[len][5] << endl;
    return 0;
}