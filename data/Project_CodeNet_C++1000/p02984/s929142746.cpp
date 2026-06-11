#include <bits/stdc++.h>
typedef long long ll;
#define rep(i, a, b) for (ll i = a; i < (ll)b; ++i)
#define digit(a) to_string(a).size()
#define INF 10e12
#define MAX 51000
#define all(x) (x).begin(), (x).end()
#define MX(x) *max_element(all(x))
#define MN(x) *min_element(all(x))
using namespace std;
int main(void)

{
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n, s = 0;
    cin >> n;
    vector<int> a(n), x(n);
    rep(i, 0, n)
    {
        cin >> a[i];
        if (i % 2 == 1)
            s += a[i];
    }
    x[0] = accumulate(all(a), 0) - 2 * s;
    rep(i, 1, n) x[i] = 2 * a[i - 1] - x[i - 1];
    rep(i, 0, n) cout << x[i] << " ";
    cout << endl;
}
