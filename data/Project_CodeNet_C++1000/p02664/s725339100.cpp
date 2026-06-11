#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef tuple<ll, ll, ll> iii;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
#define REP(i,n) for (ll i = 0; i < n; ++i)
#define REPR(i,n) for (ll i = n-1; i >= 0; --i)
#define FOR(i,m,n) for (ll i = m; i < n; ++i)
#define FORR(i,m,n) for (ll i = n-1; i >= m; --i)
#define FORE(x,xs) for (const auto& x : xs)
#define FORI(i,v) for (auto i = v.begin(); i != v.end(); i++)
#define ALL(v) v.begin(), v.end()
#define CHMIN(x,y) x = min(x, y)
#define CHMAX(x,y) x = max(x, y)
#define YES(b) cout << ((b) ? "YES" : "NO") << endl
#define Yes(b) cout << ((b) ? "Yes" : "No") << endl

const int MAX = 2e5+10;

string T;

int dp[MAX][2];

string solve() {
    if (T[0] == 'D') {
        dp[0][0] = 1;
        dp[0][1] = -100;
    } else if (T[0] == 'P') {
        dp[0][0] = 0;
        dp[0][1] = 0;
    } else {
        dp[0][0] = 1;
        dp[0][1] = 0;
    }
    REP (i, T.size()-1) {
        if (T[i+1] == 'D') {
            dp[i+1][0] = max(dp[i][0]+1, dp[i][1]+2);
            dp[i+1][1] = -100;
        } else if (T[i+1] == 'P') {
            dp[i+1][0] = 0;
            dp[i+1][1] = max(dp[i][0], dp[i][1]);
        } else {
            dp[i+1][0] = max(dp[i][0]+1, dp[i][1]+2);
            dp[i+1][1] = max(dp[i][0], dp[i][1]);
        }
    }
    string ret;
    if (T[T.size()-1] == 'P') ret = "P";
    else ret = "D";

    REPR (i, T.size()-1) {
        if (T[i] != '?') {
            ret += T[i];
            continue;
        }
        if (ret[ret.size()-1] == 'D') {
            if (dp[i][0] > dp[i][1]+1) ret += 'D';
            else ret += 'P';
        } else {
            if (dp[i][0] > dp[i][1]) ret += 'D';
            else ret += 'P';
        }
    }
    reverse(ALL(ret));
    return ret;
}

int main() {
    cout << fixed << setprecision(15);
    cin >> T;
    cout << solve() << endl;
}