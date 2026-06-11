#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<vector<int>> a(k, vector<int>(n, 0));
    vector<int> d(k);
    rep(i, k) {
        cin >> d[i];
        rep(j, d[i]) cin >> a[i][j];
    }

    vector<bool> s(n, false);
    rep(i, k) {
        rep(j, d[i]) {
            s[a[i][j] - 1] = true;
        }
    }

    int ans = 0;
    rep(i, n) {
        if (s[i] == false) ++ans;
    }

    cout << ans << endl;

    return 0;
}
