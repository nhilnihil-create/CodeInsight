#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;

int main()
{
    ll n, l[2000], ans = 0;
    cin >> n;
    rep(i, n) cin >> l[i];
    sort(l, l + n);

    for (int i = 0; i < n - 2; i++)
    {
        for (int j = i + 1; j < n - 1; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if (l[k] < l[i] + l[j])
                {
                    ans++;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}