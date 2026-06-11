#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define sz(a) (int)a.size()
#define all(a) a.begin(), a.end()
using ll = long long;
using V = vector<int>;
using VV = vector<vector<int>>;
using P = pair<int, int>;

int main()
{
    int n;
    cin >> n;
    V b(n - 1);
    rep(i, n - 1) cin >> b[i];
    ll ans = 0;
    rep(i, n)
    {
        if (i == 0)
            ans += b[i];
        else if (i == n - 1)
            ans += b[n - 2];
        else
        {
            ans += min(b[i - 1], b[i]);
        }
    }
    cout << ans << endl;
    return 0;
}