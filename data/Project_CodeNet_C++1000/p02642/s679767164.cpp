#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int mx = *max_element(a, a + n);
    bool dp[mx + 1];
    bool vis[mx + 1];
    memset(dp, true, sizeof(dp));
    memset(vis, false, sizeof(vis));
    sort(a, a + n);
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (dp[a[i]] && !vis[a[i]])
        {
            vis[a[i]] = true;
            for (int p = a[i] * 2; p <= mx; p += a[i])
            {
                dp[p] = false;
            }
        }
        else if (vis[a[i]])
        {
            dp[a[i]] = false;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (dp[a[i]])
        {
            cnt++;
        }
    }
    cout << cnt;
}