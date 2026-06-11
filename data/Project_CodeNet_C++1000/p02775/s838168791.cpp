#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int (i)=(0);(i)<(int)(n);++(i))
using ll = long long;
using namespace std;

string N;
ll dp[1010101][2];

int main() {
    cin >> N;
    reverse(N.begin(), N.end());

    int n = N.size();
    rep(i, n+1) rep(d, 2) dp[i][d] = 1e12;
    dp[0][0] = 0;
    rep(i, n) rep(d, 2) {
        if (dp[i][d] != 1e12) {
            int c = N[i] - '0' + d;
            dp[i+1][0] = min(dp[i+1][0], dp[i][d] + c);
            dp[i+1][1] = min(dp[i+1][1], dp[i][d] + 10 - c);
        }
    }

    cout << min(dp[n][0], dp[n][1] + 1) << endl;
}
