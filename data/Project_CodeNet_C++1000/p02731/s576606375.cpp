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
        int n;
        cin >> n;
        double len = (double)n / 3;
        // cout << len << "\n";
        double ans = len * len * len;
        cout << fixed << setprecision(12) << ans << "\n";
    }
}