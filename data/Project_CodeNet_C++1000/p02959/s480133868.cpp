#include <bits/stdc++.h>
#define repl(i, l, r) for (int i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using P = pair<int, int>;

int main()
{
    int n;
    cin >> n;
    vector<ll> a(n + 1);
    vector<ll> b(n);
    rep(i, n + 1) cin >> a[i];
    rep(i, n) cin >> b[i];
    ll ans = 0;
    rep(i, n) {
        int left = min(a[i], b[i]);
        ans += left;
        a[i] -= left;
        b[i] -= left;
        int right = min(a[i + 1], b[i]);
        ans += right;
        a[i + 1] -= right; 
        b[i] -= right;
    }
    cout << ans << endl;
    return 0;
}
