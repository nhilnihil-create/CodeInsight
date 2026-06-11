#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define F first
#define S second
#define pb push_back
#define mp make_pair

const int MOD = 1000000007;
const int N = 1e5 + 18;



int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif
    int t = 1;
    //cin >> t;
    while (t--) {

        int n, k;
        cin >> n >> k;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int l = 0, r = 1e9;
        while (l + 1 < r)
        {
            int m = (l + r) / 2;
            int s = 0;
            for (int i = 0; i < n; i++)
            {
                s += (a[i] + m - 1) / m - 1;
            }
            if (s <= k)
                r = m;
            else
                l = m;

        }
        cout << r << endl;

    }
    return 0;

}

