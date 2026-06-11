#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define _USE_MATH_DEFINES
#include <math.h>
#include <map>
#include <queue>
#include <cassert>
#include <iomanip>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define ALL(a) (a).begin(), (a).end()
#define rALL(a) (a).rbegin(), (a).rend()
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int iINF = 1001001001;
const long long llINF = 1LL << 60;
vector<ll> divisor(ll n)
{
    vector<ll> ret;
    for (ll i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            ret.push_back(i);
            if (i * i != n)	ret.push_back(n / i);
        }
    }
    return ret;
}
int main()
{
    /*int a, b; cin >> a >> b;
    if (a < 10 && b < 10) cout << a * b << endl;
    else cout << -1 << endl;
    */

    /*int n; cin >> n;
    rep(i, 10) rep(j, 10) {
        if (n == i * j) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    */

    /*ll n; cin >> n;
    vector<ll> d;
    d = divisor(n);
    sort(ALL(d));
    ll ans = 0;
    if (d.size() % 2 == 1) {
        ans += d[d.size() / 2] - 1;
        ans += d[d.size() / 2] - 1;
    }
    else {
        ans += d[d.size() / 2] - 1;
        ans += d[d.size() / 2 - 1] - 1;
    }
    cout << ans << endl;
    */

    int a, b, x; cin >> a >> b >> x;
    double c = 2.0 * x / double(a * a) - double(b);
    double ans;
    if (0 < c) {
        ans = atan(double(a) / (double(b) - double(c))) * 180.0 / M_PI;
    }
    else {
        ans = atan((2 * x) / (double(a) * double(b) * double(b))) * 180.0 / M_PI;
    }
    if (ans < 0) ans += 180;
    ans = 90 - ans;
    cout << setprecision(15) << ans << endl;

    return 0;
}
