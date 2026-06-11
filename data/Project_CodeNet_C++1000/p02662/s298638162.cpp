#include <bits/stdc++.h>
#define FORR(i, a, b)  for (int i = (a); i <= (b); ++i)
#define FORD(i, a, b)  for (int i = (b); i >= (a); --i)
#define REPP(i, a, b)  for (int i = (a); i < (b); ++i)
#define REPD(i, a, b)  for (int i = (b); i > (a); --i)
#define fi             first
#define se             second
#define mp             make_pair
#define pb             push_back
#define pf             push_front
#define cmin(a, b)     if ((a) > (b)) (a) = (b)
#define cmax(a, b)     if ((a) < (b)) (a) = (b)
#define BIT(x, i)      (((x) >> (i)) & 1)
#define MASK(i)        (1LL << (i))
#define debug(x)       cout << (x) << "\n"
#define endl           "\n"
#define ii             pair <int, int>
#define ll             long long
#define reset(x)       memset(x, 0, sizeof(x))
#define mem(a, x)      memset(x, (a), sizeof(x))
#define task           ""
#define IO             freopen (task".inp","r",stdin),freopen (task".out","w",stdout);

using namespace std;

const int mod = 1007050321;
const int base = 521;
const int MOD = 998244353;
const int inf = 2e9;
const int N = 2e5 + 5;

int n, s;
vector<vector<int>> dp;

int main() {
    ios_base :: sync_with_stdio(0),cin.tie(0),cout.tie(0);

    cin >> n >> s;
    dp.resize(n+1, vector<int>(s+1));
    for (int i = 0; i <= n; ++i)
        for (int j = 0; j <= s; ++j)
            dp[i][j] = 0;
    dp[0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        for (int j = 0; j <= s; ++j) {
            dp[i][j] += 1LL * 2 * dp[i-1][j] % MOD;
            if (j >= x)
                dp[i][j] += dp[i-1][j-x];
            dp[i][j] %= MOD;
        }
    }
    cout << dp[n][s];
    return 0;
}
