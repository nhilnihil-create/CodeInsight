#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=(0);(i)<(int)(n);++(i))
using ll = long long;
using P = pair<int, int>;
using namespace std;

#define INF ((1<<30)-1)
#define LLINF (1LL<<60)
#define EPS (1e-10)

// 最後にどの桁をみたか
// 現時点で何文字を残すと決めたか
// 現時点で残すとっ決まった部分の文字列
// S = 869120
// dp[3][2][89]:
// -> dp[4][2][89] or dp[4][3][891]のどちらかに分岐
// DPで求めることができる
bool dp[303030][4][1010];
string S;
int N;

int main() {
    cin >> N >> S;
    dp[0][0][0] = true;

    for (int i = 0; i < N; ++i) {
        for (int len = 0; len <= 3; ++len) {
            for (int sum = 0; sum < 1000; ++sum) {
                if (!dp[i][len][sum]) continue;
                dp[i+1][len][sum] = true;
                if (len <= 2) {
                    dp[i+1][len + 1][sum * 10 + (S[i] - '0')] = true;
                }
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < 1000; ++i) {
        if (dp[N][3][i]) ans++;
    }
    cout << ans << endl;
}
