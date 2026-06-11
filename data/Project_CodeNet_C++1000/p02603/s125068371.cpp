#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <map>
#include <queue>
#include <cassert>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define ALL(a) (a).begin(), (a).end()
#define rALL(a) (a).rbegin(), (a).rend()
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int iINF = 1001001001;
const long long llINF = 1LL << 60;
int main()
{
    int n; cin >> n;
    vector<ll> a(n);
    vector<pair<int, bool>> trade; // true: buy, false: sell
    rep(i, n) cin >> a[i];
    ll ans = 1000;
    ll stock = 0;
    int old = 0;
    bool up = false;
    rep(i, n) {
        if (i == 0) {
            old = a[i]; continue;
        }
        if (old < a[i]) up = true;
        else if (a[i] < old && up) {
            trade.emplace_back(i - 1, false);
            up = false;
        }
        old = a[i];
    }
    if (up) trade.emplace_back(n - 1, false);
    bool down = false;
    for (int i = n - 1; i >= 0; --i) {
        if (i == n - 1) {
            old = a[i]; continue;
        }
        if (a[i] < old) down = true;
        else if (old < a[i] && down) {
            trade.emplace_back(i + 1, true);
            down = false;
        }
        old = a[i];
    }
    if (down) trade.emplace_back(0, true);
    sort(ALL(trade));
    rep(i, trade.size()) {
        if (trade[i].second == true) {
            stock += ans / a[trade[i].first];
            ans -= a[trade[i].first] * (ans / a[trade[i].first]);
        }
        else {
            ans += a[trade[i].first] * stock;
            stock = 0;
        }
    }
    cout << ans << endl;
}