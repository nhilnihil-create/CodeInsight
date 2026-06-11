#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007

signed main()
{
    int n, k;
    cin >> n >> k;
    vector<int> pref(n+1), suf(n+1);
    for (int i = 1; i <= n; i++)
        pref[i] = suf[i] = i;
    for (int i = 1; i <= n; i++)
        pref[i] += pref[i-1];
    for (int i = n-1; i >= 0; i--)
        suf[i] += suf[i+1];

    int ans = 0;
    for (int i = k; i <= n+1; i++)
    {
        ans += suf[n+1-i] - pref[i-1] + 1;
        ans %= mod;
    }
    cout << ans << "\n";
}