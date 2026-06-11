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
        for (int i = 1; i <= n; ++i)
        {
            if ((int)(i * 1.08) == n)
            {
                cout << i;
                return 0;
            }
        }
        cout << ":(";
    }
}