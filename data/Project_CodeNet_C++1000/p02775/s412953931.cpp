#include <algorithm>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
#define rep(i, n) for(int(i) = 0; (i) < (n); (i)++)
#define FOR(i, m, n) for(int(i) = (m); (i) < (n); (i)++)
#define All(v) (v).begin(), (v).end()
#define pb push_back
#define MP(a, b) make_pair((a), (b))
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int INF = 1 << 30;
const ll LINF = 1LL << 60;
const int MOD = 1e9 + 7;

int main() {

    vector<vector<ll>> dp(1000100, vector<ll>(2, LINF));

    string N;
    cin >> N;

    reverse(All(N));
    N.push_back('0');
    reverse(All(N));
    dp[0][0] = 0;
    // dp[i][j]:=i文字目まで見て状態がjのときの最小
    int cnt = 0;
    rep(i, N.size()) {
        // j==0 今までぴったり
        dp[i + 1][0] = min(dp[i + 1][0], dp[i][0] + (N[i] - '0'));
        if(N[i] != '9')
            dp[i + 1][1] = min(dp[i + 1][1], dp[i][0] + (N[i] - '0') + 1);

        // j==1 1余分に払ってる
        dp[i + 1][0] = min(dp[i + 1][0], dp[i][1] + (10 - (N[i] - '0')));
        dp[i + 1][1] = min(dp[i + 1][1], dp[i][1] + (9 - (N[i] - '0')));
        cnt++;
    }

    cout << dp[N.size()][0] << endl;
    return 0;
}