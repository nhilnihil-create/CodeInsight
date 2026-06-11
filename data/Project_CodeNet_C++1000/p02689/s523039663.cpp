#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> h(n);
    rep(i, n) cin >> h[i];
    vector<int> a(m);
    vector<int> b(m);
    rep(i, m) {
        cin >> a[i];
        --a[i];
        cin >> b[i];
        --b[i];
    }
    vector<int> ma(n, 0);
    rep(i, m) {
        ma[a[i]] = max(ma[a[i]], h[b[i]]);
        ma[b[i]] = max(ma[b[i]], h[a[i]]);
    }

    int ans = 0;
    rep(i, n) {
        if(h[i] > ma[i]) ++ans;
    }

    cout << ans << endl;

    return 0;
}
