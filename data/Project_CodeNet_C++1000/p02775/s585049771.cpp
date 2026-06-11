#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using vc = vector<char>;
using vvc = vector<vc>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;
const ll INF = 1LL << 60;
const ll MOD = 1e9 + 7;
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define debug(x) cerr << #x << ": " << x << endl;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

const ll NX = 1100000;
ll dp[NX][2];
int main() {
    string s;
    cin >> s;
    reverse(s.begin(), s.end());
    s += '0';
    ll n = s.size();

    rep(i,NX) rep(j,2) dp[i][j] = INF;
    dp[0][0] = 0;
    rep(i,n) rep(j,2) {
        ll d = s[i] - '0';
        d += j;
        if(d < 10) chmin(dp[i+1][0], dp[i][j] + d);
        if(d > 0) chmin(dp[i+1][1], dp[i][j] + 10 - d);
    }
    cout << dp[n][0] << endl;
}