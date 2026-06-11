#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll n, ans = 0, maxn = 0, j;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> j;
        if (i == 1)
            maxn = j;
        else
        {
            if (maxn > j)
                ans += maxn - j;
            else
                maxn = j;
        }
    }
    cout << ans << endl;
    return 0;
}