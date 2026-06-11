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
    //   cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;
        int ans = -1;
        for (int i = 1; i <= 1000; ++i)
        {
            int x = i * 8;
            x /= 100;
            int y = i * 10;
            y /= 100;
            if (x == a && y == b)
            {
                ans = i;
                goto ll;
            }
        }

    ll:
        cout << ans << "\n";
    }
}