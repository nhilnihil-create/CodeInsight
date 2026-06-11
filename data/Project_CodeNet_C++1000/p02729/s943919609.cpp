#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;

int Comb(int m, int n)
{
    if (m == n || n == 0)
        return 1;

    int ans = 1;
    for (int i = 1; i <= n; i++)
    {
        ans = ans * (m - i + 1) / i;
    }
    return ans;
}

int main()
{
    int n, m, ans = 0;
    cin >> n >> m;

    if (n > 1)
        ans += Comb(n, 2);
    if (m > 1)
        ans += Comb(m, 2);

    cout << ans << endl;
}