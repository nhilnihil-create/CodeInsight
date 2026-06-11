/*
    Problem 6
    https://atcoder.jp/contests/sumitrust2019/tasks/sumitb2019_d
*/
#include <bits/stdc++.h>
using namespace std;
/* typedef */
typedef long long ll;
typedef pair<int, int> pii;
/* constant */
const int INF = 1 << 30;
const int NIL = -1;
const int MAX = 10000;
const int mod = 1000000007;
const double pi = 3.141592653589;
/* global variables */
/* function */
void solve1() {
    int N; string S;
    cin >> N >> S;
    int ans = 0;
    // 000 ~ 999までがSに含まれるか全探索
    // O(10^3 * 3 * 10^4) = O(3 * 10^7)
    for (int i = 0; i < 1000; i++) {
        vector<int> v{i / 100, (i / 10) % 10, i % 10};
        int t = 0;
        for (int s = 0; s < N; s++) {
            if (S[s] == ('0' + v[t])) t++;
            if (t >= 3) {
                ans++;
                break;
            }
        }
    }
    cout << ans << '\n';
}

void solve2() {
    int N; string S;
    cin >> N >> S;
    // dp[len][num]
    // len : 何文字で
    // num : numができるか
    // ex)
    // dp[2][2] => 02
    // dp[3][2] => 002
    vector<vector<bool>> dp(4, vector<bool>(1000));
    for (int pos = 0; pos < N; pos++) {
        int cur = S[pos] - '0';
        // dp[2][num] => dp[3][num*10 + cur]
        for (int num = 0; num < 100; num++) if (dp[2][num]) dp[3][cur + num * 10] = true;
        // dp[1][num] => dp[2][num*10 + cur]
        for (int num = 0; num < 10; num++) if (dp[1][num]) dp[2][cur + num * 10] = true;
        // dp[1][cur]
        dp[1][cur] = true;
    }
    int ans = accumulate(dp[3].begin(), dp[3].end(), 0);
    cout << ans << '\n';
}
/* main */
int main(){
    // solve1();
    solve2();
}