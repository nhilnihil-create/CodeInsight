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
    //cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int vis[n + 1];
        memset(vis, 0, sizeof(vis));
        map<int, int> mp;
        while (m--)
        {
            int x;
            string s;
            cin >> x >> s;
            if (s == "WA")
            {
                if (!vis[x])
                    mp[x]++;
            }
            else
            {
                vis[x] = 1;
            }
        }
        int tota = 0, totp = 0;
        for (int i = 1; i <= n; ++i)
        {
            if (vis[i])
            {
                tota++;
                totp += mp[i];
            }
        }
        cout << tota << " " << totp << "\n";
    }
}