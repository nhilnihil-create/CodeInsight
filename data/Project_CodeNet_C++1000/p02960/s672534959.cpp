// 6/26 解き直し → 6/30
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;
const int INF = 1000000007;

// S = '034235??452'
// ? を変えて13で割って5余る数にする組み合わせ。

// dp[i][j]
// ?のi番目までを使ってj(mod13)となる数の組み合わせ。
// ?の個数をQとすると、最終的にdp[Q][5]が答え。

const int MOD = 1000000007;

const int mod = 13;
int dp[100010][15];

int main() {
    string S;
    cin >> S;

    int n = S.size();
    int now = 1;

    vector<int> A;  // 小さい方から数えてi番目の?の桁のmodを格納する
    int init = 0;  // 初めのmod

    for (int i = n-1; i >= 0; i--) {
        // cout << "here?" << endl;
        if (S[i] == '?') {
            A.push_back(now);
        } else {
            int x = S[i] - '0';
            init = (init + x * now) % mod;
        }
        now = (now * 10) % mod;
    }

    // printf("init, A.size() = %d, %d\n", init, A.size());
    // printf("%d\n", 2005 % mod);
    // for (auto a : A) cout << a << " ";
    // cout << endl;

    int q = A.size();

    rep(i, q+1) rep(j, mod) dp[i][j] = 0;
    // dp[0][0] = 1;
    dp[0][init] = 1;

    rep(i, q) {
        for (int j = 0; j < mod; j++) {
            // if (dp[i][j] == -1) continue;
            if (dp[i][j] == 0) continue;
            for (int k = 0; k < 10; k++) {
                int nj = (j + k * A[i]) % mod;
                dp[i+1][nj] += dp[i][j];
                dp[i+1][nj] %= MOD;
            }
        }
    }

    cout << dp[q][5] << endl;
    return 0;
}