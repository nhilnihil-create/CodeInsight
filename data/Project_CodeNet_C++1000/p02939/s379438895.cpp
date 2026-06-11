#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

const int MAX_N = 202020;
const int INF = 1001001001;

int dp[MAX_N][3];

int main() {
    string s;
    cin >> s;
    int n = s.size();
    for (int i = 0; i < MAX_N; i++) for (int j = 0; j < 3; j++) dp[i][j] = -INF;
    dp[0][0] = 0;
    for (int i = 0; i < n; i++) {
        for (int pre = 0; pre < 3; pre++) {
            if (dp[i][pre] < 0) continue;
            for (int nxt = 1; nxt < 3; nxt++) {
                if (pre == nxt) {
                    if (nxt == 1) {
                        if (s[i - 1] == s[i]) continue;
                    } else {
                        if (s[i - 2] == s[i] && s[i - 1] == s[i + 1]) continue;
                    }
                }
                dp[i + nxt][nxt] = max(dp[i + nxt][nxt], dp[i][pre] + 1);
            }
        }
    }
    cout << max(dp[n][1], dp[n][2]) << endl;
}