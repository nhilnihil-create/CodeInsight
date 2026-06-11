#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007

//read question carefully!

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        int sum = 0;
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
            sum += a[i];
        }
        int p = sum / n;
        //cout << p << "\n";
        int ans = 0, ans1 = 0;

        for (int i = 0; i < n; ++i)
        {
            int val = abs(a[i] - p);
            ans += val * val;
        }
        p++;
        for (int i = 0; i < n; ++i)
        {
            int val = abs(a[i] - p);
            ans1 += val * val;
        }
        cout << min(ans, ans1) << "\n";
    }
}