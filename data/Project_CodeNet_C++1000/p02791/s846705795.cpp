#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int n;
    cin >> n;
    vector<int> p(n);
    rep(i, n) cin >> p[i];
    int mn = 1e9, ans = 0;
    rep(i, n)
    {
        mn = min(mn, p[i]);
        if (mn == p[i])
            ans++;
    }
    cout << ans << endl;
    return 0;
}