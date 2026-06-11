#include <bits/stdc++.h>
#define int long long int
#define endl "\n"
#define mod 1000000007
#define ps(x,noOfDecimal) fixed<<setprecision(noOfDecimal)<<x

using namespace std;

signed main()
{
    if (fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    }
    std::ios::sync_with_stdio(false);
    int t = 1;
    // cin >> t;
    while (t--) {
        int n, tl;
        cin >> n >> tl;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            int a; cin >> a;
            if (a >= tl)cnt++;
        }
        cout << cnt;
    }
    return 0;
}