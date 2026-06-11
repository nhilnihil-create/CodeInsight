#include <bits/stdc++.h>

using namespace std;
#define ll long long
const int N = 5e3 + 5;
int dp[N][N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = 0;
    for (int i = n - 1; i >= 0; i--) {
        for (int j = n - 1; j >= i; j--) {
            if (s[i] == s[j]) dp[i][j] = 1 + dp[i + 1][j + 1];
            ans = max(ans, min(dp[i][j], j - i));
        }
    }
    cout << ans << endl;
    return 0;
}