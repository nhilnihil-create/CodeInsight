/*input
1000000000000000 1000000000000000 1000000000000000
*/

#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    ll x, k, d;
    cin>> x >> k >> d;

    x = abs(x);
    if (k%2 == 1) x = abs(x-d), --k;
    ll ans = x%(2*d);
    auto f = [](ll a, ll b){ return abs(a) < abs(b);};
    ans = min(ans, ans-2*d, f);
    if ((x-ans)/d > k) ans = x-k*d;
    // ans = max(ans, x-k*d);
    ans = abs(ans);
    cout << ans << endl;
}