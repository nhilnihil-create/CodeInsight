#include <bits/stdc++.h>
using namespace std;

const long long N = 2e5 + 5;

long long n, m, T, a[N], b[N];

int main()
{
    cin >> n >> m >> T;
    for (long long i = 1; i <= n; i++) cin >> a[i];
    for (long long i = 1; i <= m; i++) cin >> b[i];

    long long res = 0, R = 0, Sum = 0;
    while (R < m && Sum + b[R + 1] <= T)
        Sum += b[++R];
    res = R;
    for (long long i = 1; i <= n; i++) {
        Sum += a[i];
        while (R > 0 && Sum > T) {
            Sum -= b[R];
            R--;
        }
        if (Sum <= T) res = max(res, R + i);
    }

    cout << res;
}
