#include <bits/stdc++.h>

#define int long long

using namespace std;

const int maxn = 1e5 + 10;
int a[maxn], n, m, v, p;

bool f(int h)
{
    int x = p - 1 + n - h, s = max(0ll, v - x) * m;
    for (int i = p - 1; i < h; i++) {
        if (a[i] > a[h] + m)
            return false;
        s -= min(m, a[h] + m - a[i]);
    }
    return s <= 0;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m >> v >> p;

    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n, greater<int>());

    int l = 0, r = n;
    while (r - l > 1)
    {
        int mid = l + r >> 1;
        if (f(mid))
            l = mid;
        else
            r = mid;
    }

    cout << r;

    return 0;
}
