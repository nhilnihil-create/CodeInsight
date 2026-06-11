#include <bits/stdc++.h>
using namespace std;

#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
#define endl "\n"
#define int long long

const int N = 2005;

int n;
int a[N], cache[N][N];
pair<int, int> b[N];

int dp(int idx, int i, int j)
{
    if (idx > n)
        return 0;
    int &ans = cache[idx][i];
    if (ans != -1)
        return ans;
    ans = abs(i - b[idx].second) * b[idx].first + dp(idx + 1, i + 1, j);
    ans = max(ans, abs(j - b[idx].second) * b[idx].first + dp(idx + 1, i, j - 1));
    return ans;
}

int32_t main()
{
    IOS;
    memset(cache, -1, sizeof(cache));
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        b[i].first = a[i];
        b[i].second = i;
    }
    sort(b + 1, b + n + 1);
    reverse(b + 1, b + n + 1);
    int ans = dp(1, 1, n);
    cout << ans;
    return 0;
}
