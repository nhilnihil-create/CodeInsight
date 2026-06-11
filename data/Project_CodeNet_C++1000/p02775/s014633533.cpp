#include <bits/stdc++.h>
using namespace std;
#ifdef DEBUG
#define FPEN freopen("in.txt", "r", stdin);
#define debug(...) \
    { cerr << "# " << __VA_ARGS__ << "\n"; }
#else
#define debug(...)
#define FPEN
#endif
const int maxn = 200009;
typedef long long i64;
typedef pair<i64, i64> pi64;
typedef pair<int, int> pi;
const i64 MOD = 119 << 23 | 1;
class {
   public:
    int dp[1000009][2];
    void solve() {
        string s;
        cin >> s;
        dp[0][0] = 0;
        dp[0][1] = 1;
        for (int i = 1; i <= s.size(); ++i) {
            int num = s[i - 1] - '0';
            dp[i][0] = min(dp[i - 1][1] + 10 - num, dp[i - 1][0] + num);
            if (num != 9) {
                num++;
                dp[i][1] = min(dp[i - 1][1] + 10 - num, dp[i - 1][0] + num);
            } else {
                dp[i][1] = dp[i - 1][1];
            }
        }
        cout << dp[s.size()][0] << '\n';
    }
} NSPACE;
int main() {
    FPEN;
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    NSPACE.solve();
}