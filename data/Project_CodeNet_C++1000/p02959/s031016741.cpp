#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
/////////////////////////////////
int main()
{
    int n;
    cin >> n;
    vector<ll> a(n + 1), b(n);
    rep(i, n + 1) cin >> a[i];
    rep(i, n) cin >> b[i];
    ll ans = 0;
    rep(i, n)
    {
        ll k;
        k = min(a[i], b[i]);
        ans += k;
        b[i] -= k;
        k = min(a[i + 1], b[i]);
        ans += k;
        a[i + 1] -= k;
    }
    cout << ans << endl;
}