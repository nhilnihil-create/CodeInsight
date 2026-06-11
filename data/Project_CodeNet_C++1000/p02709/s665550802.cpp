#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
typedef long long ll;
using namespace std;

typedef pair<ll, int> P;
#define fs first
#define sc second

ll INF = 1LL << 60;

int main() {
    int N;
    cin >> N;
    P p[N];
    for(int i = 0; i < N; i++){
        cin >> p[i].fs;
        p[i].sc = i;
    }

    sort(p, p + N, greater<P>());

    //大きい方からi個つかって、左に詰めたのがjこのときのスコアmax
    vector<vector<ll>> dp(N + 1, vector<ll>(N + 1, -INF));
    dp[0][0] = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j <= i; j++) {
            //右に詰めた数
            int k = i - j;

            //左に詰める
            dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + p[i].fs * (p[i].sc - j));

            //右に詰める
            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + p[i].fs * (N - k - 1 - p[i].sc));
        }
    }

    ll ans = 0;
    for(int j = 0; j <= N; j++) {
        ans = max(ans, dp[N][j]);
    }

    cout << ans << endl;
    return 0;
}