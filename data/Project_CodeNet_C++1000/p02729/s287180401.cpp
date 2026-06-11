#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    //cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;
        int ans = a * (a - 1) / 2;
        ans += b * (b - 1) / 2;
        cout << ans << "\n";
    }
}