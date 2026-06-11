#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int INF = 1 << 29;
const int MOD = 1000000007;

int main() {
    long long n, m;
    cin >> n >> m;

    // 0段目からn段目のどこが壊れていないか(0段目とn段目は壊れてない)
    vector<bool> not_broken(n + 1, true);
    long long a;
    rep(i, m) {
        cin >> a;
        not_broken.at(a) = false;
    }

    // dp[i] = i段目まで登るときの場合の数としたときdp[i] = dp[i-1] + dp[i-2]となる
    // dp[i]が壊れているとき0を代入(何もしない)
    vector<long long> dp(n + 1, 0);
    // 0段目にあるという意味で1通り
    dp.at(0) = 1;
    // 1段目だけ別判定する  壊れてないとき1通り
    if (not_broken.at(0) == true) dp.at(1) = 1;

    for (int i = 2; i <= n; i++) {
        // i番目が壊れているとき何もしない(0のまま)
        if (not_broken.at(i) == false) continue;

        // i番目が壊れていないとき
        if (not_broken.at(i - 2) == true) dp.at(i) += dp.at(i - 2);
        if (not_broken.at(i - 1) == true) dp.at(i) += dp.at(i - 1);

        // MODを取る
        dp.at(i) %= MOD;
    }
    // 途中が全て壊れているときも大丈夫
    cout << dp.at(n) << endl;
}
