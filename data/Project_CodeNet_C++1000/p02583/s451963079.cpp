#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int check(int i, int j, int k)
{
    if (i + j <= k)
        return 0;
    else
        return 1;
}
int main()
{
    ll n, a[105];
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int ans = 0;
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n - 2; i++)
    {
        for (int j = i + 1; j <= n - 1; j++)
        {
            if (a[j] == a[i])
                continue;
            for (int k = j + 1; k <= n; k++)
            {
                if (a[k] == a[j])
                    continue;
                if (check(a[i], a[j], a[k]))
                    ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}