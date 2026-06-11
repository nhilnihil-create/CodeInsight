#include <bits/stdc++.h>

using namespace std;

#define sz(x) (int) x.size()
#define all(a) a.begin(), a.end()

const int MAXN = 2050;

int n;
pair<int, int> a[MAXN];
long long dp[MAXN][MAXN];

long long calc(int pos, int l) {
    long long& res = dp[pos][l];
    if (res != -1) 
        return res;

    res = 0;
    if (pos == n)
        return res;

    int r = n - 1 - (pos - l);
    res = 1ll * a[pos].first * abs(a[pos].second - l) + calc(pos + 1, l + 1);
    res = max(res, 1ll * a[pos].first * abs(a[pos].second - r) + calc(pos + 1, l));

    return res;
}

int main() {

    scanf("%d", &n);
    for (int i = 0; i < n; i++) { 
        scanf("%d", &a[i].first);
        a[i].second = i;
    }

    sort(a, a + n);
    reverse(a, a + n);

    memset(dp, -1, sizeof(dp));
    cout << calc(0, 0) << endl;

    return 0;
}
