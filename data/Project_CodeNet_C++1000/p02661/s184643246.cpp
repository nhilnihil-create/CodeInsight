#include <bits/stdc++.h>
#define fi first
#define se second
#define ii pair<int, int>
#define int long long
using namespace std;

int a[200005], b[200005];

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

//    freopen("in.inp", "r", stdin);
//    freopen("out.out", "w", stdout);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i] >> b[i];
    sort(a+1, a+n+1);
    sort(b+1, b+n+1);
    if (n % 2 == 0)
    {
        int s1 = (a[n/2] + a[n/2 + 1]) ;
        int s2 = (b[n/2] + b[n/2 + 1]) ;
        cout << (s2 - s1) + 1;
    } else {
        cout << (b[(n+1)/2] - a[(n+1)/2]) + 1;
    }
}
