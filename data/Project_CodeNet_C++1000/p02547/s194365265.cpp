#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
    #include "debug.cpp"
#endif

#define int long long

void solve()
{
    int n;
    cin >> n;
    int a[n][2];
    for(int i = 0; i < n; i++)
        cin >> a[i][0] >> a[i][1];
    for(int i = 1; i < n - 1; i++)
    {
        if(a[i][0] == a[i][1] && a[i - 1][0] == a[i - 1][1] && a[i + 1][0] == a[i + 1][1])
        {
            cout << "Yes\n";
            return;
        }
    }
    cout << "No\n";
}

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}