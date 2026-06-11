#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <cmath>
#include <unordered_map>

#define MaxN 2010

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int n;
int a[MaxN];
pii a_p[MaxN];
ll dp[MaxN][MaxN];


int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        a_p[i] = make_pair(a[i], i);
    }
    sort(a_p + 1, a_p + n + 1, greater<pii>());
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + (ll)a_p[i].first * (ll)abs(a_p[i].second - j));
        }
        for (int j = 0; j < i; ++j) {
            dp[i][j] = max(dp[i][j], dp[i - 1][j] + (ll)a_p[i].first * (ll)abs(n - (i - j) + 1 - a_p[i].second));
        }
    }
    ll ans = 0;
    for (int i = 0; i <= n; ++i) {
        ans = max(ans, dp[n][i]);
    }
    cout << ans << endl;
    return 0;
}