#include <iostream>
#include <vector>
using namespace std;
const int MOD = 1000000007;

int N, M;
vector<bool> issafe; // issafe[v] := v が壊れていないかどうか

int main() {
    cin >> N >> M;
    issafe.assign(N+1, true);
    for (int i = 0; i < M; ++i) {
        int a; cin >> a;
        issafe[a] = false; // a 段目は壊れてる
    }

    // DP テーブル
    vector<int> dp(N+1, 0); // 各段について 0 で初期化しておく

    // 初期条件
    dp[0] = 1;
    if (issafe[1]) dp[1] = 1;

    // ループ
    for (int n = 2; n <= N; ++n) {
        if (issafe[n-1]) dp[n] += dp[n-1]; // n-1 段目が安全なら
        if (issafe[n-2]) dp[n] += dp[n-2]; // n-2 段目が安全なら
        dp[n] %= MOD; // 1000000007 で割る
    }
    cout << dp[N] << endl;
}