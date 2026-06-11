#include <bits/stdc++.h>
typedef long long ll;
#define rep(i, a, b) for (ll i = a; i < (ll)b; ++i)
#define digit(a) to_string(a).size()
#define INF 10e12
#define MAX 51000
#define all(x) (x).begin(), (x).end()
#define MX(x) *max_element(all(x))
#define MN(x) min_element(all(x))
using namespace std;
int main(void)

{
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n, k;
    cin >> n >> k;
    ll bin, small;
    vector<ll> a(n + 1), b(n + 1);
    a[0] = 0;
    b[0] = n;
    rep(i, 0, n) a[i + 1] = a[i] + i + 1, b[i + 1] = b[i] + n - 1 - i;
    ll ans = 0;
    rep(i, k - 1, n + 1)
        ans += b[i] - a[i] + 1;
    cout << ans % 1000000007 << endl;
}
