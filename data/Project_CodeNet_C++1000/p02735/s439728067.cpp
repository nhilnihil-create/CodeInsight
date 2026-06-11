#include <bits/stdc++.h>
#define MOD 1000000007
#define INF 1000000000
#define LINF 1000000000000000000
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define bit(n) (1LL<<(n))
using namespace std;

typedef pair<int, int> P;
typedef pair<long long, long long> LLP;

int main() {

    int H, W;
    cin >> H >> W;
    vector<string> s(H);
    rep(i,H) cin >> s[i];

    vector<vector<int>> dp(H, vector<int>(W, INF));
    dp[0][0] = (s[0][0] == '.' ? 0 : 1);
    
    for (int i = 1; i < W; i++) dp[0][i] = dp[0][i - 1] + (s[0][i - 1] == '.' && s[0][i] == '#' ? 1 : 0);
    for (int i = 1; i < H; i++) dp[i][0] = dp[i - 1][0] + (s[i - 1][0] == '.' && s[i][0] == '#' ? 1 : 0);
    for (int i = 1; i < H; i++) for (int j = 1; j < W; j++) {
        dp[i][j] = dp[i][j - 1] + (s[i][j - 1] == '.' && s[i][j] == '#' ? 1 : 0);
        dp[i][j] = min(dp[i][j], dp[i - 1][j] + (s[i - 1][j] == '.' && s[i][j] == '#' ? 1 : 0));
    }

    cout << dp[H - 1][W - 1] << endl;
    
    return 0;
}