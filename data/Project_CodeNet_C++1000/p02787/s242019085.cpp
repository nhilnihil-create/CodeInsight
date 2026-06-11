#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
using namespace std;
const int INF = 1 << 30;
template<class T> inline bool chmin(T &a, const T &b) { if (b < a) { a = b; return 1; } return 0; }


int main() {
    int H, N;
    cin >> H >> N;
    vector<int> dp(H + 1, INF);
    dp[0] = 0;
    rep(_, N) {
        int a, b;
        cin >> a >> b;
        rep(i, H) chmin(dp[min(H, i + a)], dp[i] + b);
    }
    cout << dp[H] << '\n';
}
