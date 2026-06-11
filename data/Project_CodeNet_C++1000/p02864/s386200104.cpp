#include <bits/stdc++.h>
#define INF 1e18
#define int long long
#define Rep(i, a, n) for (int i = (a); i < (n); i++)
#define rep(i, n) Rep(i, 0, n)
#define all(a) (a).begin(), (a).end()
using namespace std;
typedef pair<int, int> P;
typedef pair<int, P> PP;
const int mod = 1000000007;
//const int mod = 998244353;

int n, k;
vector<int> h;
int dp[310][310][310];
bool vis[310][310][310];

int solve(int N, int K, int P)
{
    if (vis[N][K][P])
        return dp[N][K][P];
    vis[N][K][P] = true;
    if (N == n + 1)
        return 0;
    int pre = h[P];
    int res = solve(N + 1, K, N) + max(0LL, h[N] - pre);
    if (K > 0)
    {
        res = min(res, solve(N + 1, K - 1, P));
        res = min(res, solve(N + 1, K - 1, N + 1) + max(0LL, h[N + 1] - pre));
    }
    return dp[N][K][P] = res;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;
    h.resize(n + 1);
    h[0] = 0;
    rep(i, n) cin >> h[i + 1];
    cout << solve(1, k, 0) << endl;
}