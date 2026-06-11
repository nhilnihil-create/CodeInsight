#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int n;
    cin >> n;
    vector<int> w(n);
    rep(i, n) cin >> w[i];
    int s = 0;
    rep(i, n) s += w[i];
    int t = 0, ans = 1e9;
    rep(i, n)
    {
        t += w[i];
        s -= w[i];
        int tmp = abs(t - s);
        if (tmp < ans)
            ans = tmp;
    }
    cout << ans << endl;
    return 0;
}