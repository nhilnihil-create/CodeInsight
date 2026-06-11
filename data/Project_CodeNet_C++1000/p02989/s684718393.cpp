#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int n;
    cin >> n;
    vector<int> d(n);
    rep(i, n) cin >> d[i];
    sort(d.begin(), d.end());
    int ans = 0;
    for (int k = d[n/2 - 1]; k <= d[n/2]; k++) {
        int m = lower_bound(d.begin(), d.end(), k) - d.begin();
        if (m == n/2) ans++;
    }
    cout << ans << endl;
    return 0;
}