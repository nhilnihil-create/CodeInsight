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
        int n;
        cin >> n;
        int x = n / 2;
        if ((n) % 2 != 0) x++;
        long double y = (long double)x / (long double)n;
        cout << ps(y, 6);
    }
    return 0;
}