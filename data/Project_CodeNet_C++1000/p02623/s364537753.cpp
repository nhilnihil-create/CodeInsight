#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int A[2333333], B[2333333];
ll suma[233333], sumb[233333];

int main()
{
    ios::sync_with_stdio(false);
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> A[i];
        suma[i] = suma[i - 1] + A[i];
    }
    for (int i = 1; i <= m; i++)
        cin >> B[i], sumb[i] = sumb[i - 1] + B[i];
    int ans = 0;
    for (int i = 0; i <= n; i++)
    {
        if (suma[i] > k)
            break;
        int ls = upper_bound(sumb + 1, sumb + m + 1, k - suma[i]) - sumb;
        ans = max(ans, i + ls - 1);
    }
    cout << ans << endl;
    return 0;
}