#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;

int main()
{
    int n, p[300000], min, ans = 0;
    cin >> n;
    rep(i, n) cin >> p[i];
    min = p[0];
    rep(i, n)
    {
        if (min >= p[i])
        {
            min = p[i];
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}