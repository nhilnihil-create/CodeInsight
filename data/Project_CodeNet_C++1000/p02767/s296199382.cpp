#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    ll ans = 100100100100100;
    for (int x = 1; x <= 100; x++) {
        ll tmp = 0;
        rep(i, n) {
            tmp += (a[i] - x) * (a[i] - x);
        }
        ans = min(ans, tmp);
    }
    cout << ans << endl;
    return 0;
}