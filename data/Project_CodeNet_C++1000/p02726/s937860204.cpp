#include <bits/stdc++.h>
typedef long long ll;
#define rep(i, a, n) for (ll i = a; i < (ll)n; ++i)
const int MOD = 1000000007;
using namespace std;

int main(void)
{
    ll n, x, y;
    cin >> n >> x >> y;
    vector<ll> v(n, 0);
    rep(i, 1, n + 1) rep(j, i + 1, n + 1) v[min(j - i, abs(x - i) + 1 + abs(y - j))]++;
    rep(i, 1, n) cout << v[i] << endl;
}
