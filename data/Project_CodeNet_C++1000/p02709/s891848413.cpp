#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (int)n; ++i)
#define repf(i, f, l) for(int i = f; i < (int)l; ++i)
#define repit(it, t) for(__typeof((t).begin()) it = (t).begin(); it != (t).end(); it++)
#define endl "\n"
#define pb emplace_back
#define int long long
#define lb lower_bound
#define fs first
#define sd second
#define DBG0(x) { cout << #x << ": " << x << "\t"; }
#define DBG(x) {DBG0(x); cout << endl;}
#define DBG2(x, y) {DBG0(x); DBG(y);}
#define DBG3(x, y, z) {DBG0(x); DBG2(y, z);}
#define DBG4(w, x, y, z) {DBG0(w); DBG3(x, y, z);}
#define abs(x) ((x) < 0 ? (-1 * (x)) : (x))
#define max(x, y) (((x) < (y)) ? (y) : (x))

typedef vector<int> vint;
typedef pair<int, int> pii;

#define N 2001
int dp[N][N];


void printDp(int n) {
    cout << endl;
    rep(i, n + 1) {
        rep(j, n + 1) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
}

signed main(void){
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<pii> as = vector<pii>();
    rep(i, n) {
        int a;
        cin >> a;
        as.push_back(pii(a, i));
    }
    sort(as.begin(), as.end(), [](pii& a, pii& b) { return a.first > b.first; });
    rep(i, N) rep(j, N) dp[i][j] = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; i + j < n; ++j) {
            pii cur = as[i + j];
            int dis = (n - j - 1) - cur.second;
            dp[i][j + 1] = max(dp[i][j] + cur.first * abs(dis), dp[i][j + 1]);

            dis = i - cur.second;
            dp[i + 1][j] = max(dp[i][j] + cur.first * abs(dis), dp[i + 1][j]);
        }
    }
//  printDp(n);
    int ans = 0;
    for (int i = 0; i <= n; ++i) {
        ans = max(ans, dp[i][n - i]);
    }
    cout << ans << endl;

    return 0;
}
