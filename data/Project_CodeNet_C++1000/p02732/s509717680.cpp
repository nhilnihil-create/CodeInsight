#include <bits/stdc++.h>
#define rep(i, n) for (ll(i) = 0; (i) < (n); (i)++)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;
int main()

{
    int n;
    cin >> n;
    vi a(n);
    int max = 0;
    rep(i, n)
    {
        cin >> a[i];
        if (max < a[i])
        {
            max = a[i];
        }
    }
    vl x(max + 1, 0), y(max + 1, 0), z(max + 1, 0), ans(n, 0);
    rep(i, n)
    {
        x[a[i]]++;
    }
    rep(i, max + 1)
    {
        y[i] = x[i] * (x[i] - 1) / 2;
        z[i] = (x[i] - 1) * (x[i] - 2) / 2;
        ans[0] += y[i];
    }
    for (int i = 1; i < (max + 1); i++)
    {
        ans[i] = ans[0] + z[i] - y[i];
    }
    rep(i, n)
    {
        cout << ans[a[i]] << endl;
    }

    return 0;
}