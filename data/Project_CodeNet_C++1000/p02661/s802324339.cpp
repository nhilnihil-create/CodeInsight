#include <bits/stdc++.h>
#define int long long

using namespace std;
typedef pair <int, int> ii;

int n, a[200001], b[200001];

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//    freopen("INP.INP", "r", stdin);
//    freopen("OUT.OUT", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i] >> b[i];
    sort (a + 1, a + n + 1);
    sort (b + 1, b + n + 1);
    if (n % 2 != 0) {
        cout << abs(b[(n + 1) / 2] - a[(n + 1) / 2]) + 1;
    }
    if (n % 2 == 0) {
        int mida = (a[n / 2] + a[n / 2 + 1]);
        int midb = (b[n / 2] + b[n / 2 + 1]);
        cout << abs(mida - midb) + 1;
    }
    return 0;
}
