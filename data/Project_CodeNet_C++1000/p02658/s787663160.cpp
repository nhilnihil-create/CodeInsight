#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
 
int main()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n)
    {
        cin >> a[i];
        if (a[i] == 0)
        {
            cout << 0 << endl;
            return 0;
        }
    }
    ll ans = a[0];
    const ll INF = 1e18;
    for (int i = 1; i < n; i++)
    {
        if (a[i] > INF / ans)
        {
            cout << -1 << endl;
            return 0;
        }
        else
        {
            ans *= a[i];
        }
    }
    cout << ans << endl;
}