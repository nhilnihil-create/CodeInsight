#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <queue>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <map>
#include <cmath>
#include <iomanip>
#include <cassert>
using namespace std;
#define sL(i) i << 1
#define sR(i) i << 1 | 1
#define mp make_pair
#define pb push_back
typedef long long ll;
typedef pair<int,int> pi;
typedef pair<int, pair<int,int>> ppi;
const int MOD = 1e9 + 7;
const int INF = 2e9 + 5;

int n, a[2010];
ll dp[2010][2010];
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    vector<pi> sorted;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sorted.emplace_back(a[i], i);
    }
    sort(sorted.begin(), sorted.end(), greater<pi>());
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            dp[i][j] = -INF;
        }
    }
    dp[0][0] = 0;
    for (int i = 0; i < n; i++) {
        ll cur = sorted[i].first;
        ll idx = sorted[i].second;
        for (int j = 0; j <= i; j++) if (dp[i][j] != -INF) {
            dp[i + 1][j + 1] = max(dp[i + 1][j + 1], cur * abs(idx - j) + dp[i][j]);
            dp[i + 1][j] = max(dp[i + 1][j], cur * abs(n - 1 - (i - j) - idx) + dp[i][j]);
        }
    }
    ll ans = -1;
    for (int i = 0; i <= n; i++) {
        ans = max(ans, dp[n][i]);
    }
    cout << ans;
}