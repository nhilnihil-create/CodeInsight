#include <iostream>
#include <assert.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <string.h>
#include <cmath>
#include <memory.h>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#define ll long long
using namespace std;

const int N = 2001;

int n;
ll dp[N][N];
vector<pair<int, int>> a;

// returns max after filling in [l, r]
ll go(int idx, int l, int r) {
    if (idx == n)
        return 0;
    ll &ret = dp[l][r];
    if (ret != -1)
        return ret;
    ret = go(idx + 1, l + 1, r) + a[idx].first * abs(l - a[idx].second);
    ret = max(ret, go(idx + 1, l, r - 1) + a[idx].first * abs(r - a[idx].second));
    return ret;
}

void solve() {
    cin >> n;
    a.assign(n, {0, 0});
    memset(dp, -1, sizeof dp);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a.rbegin(), a.rend());
    cout << go(0, 0, n - 1) << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1;
    while(t--)
        solve();
    return 0;
}
