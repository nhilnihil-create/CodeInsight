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
    vector<int> mx(n);
    rep(i, n) {
        cin >> h[i];
        mx[i] = 0;
    }
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        mx[a] = max(mx[a], h[b]);
        mx[b] = max(mx[b], h[a]);
    }
    int ans = 0;
    rep(i, n) {
        if (h[i] > mx[i]) ans++;
    }
    cout << ans << endl;
    return 0;
}