#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int mod = 1000000007;

bool cmp(pair<ll, ll> x, pair<ll, ll> y) {
  	if (y == make_pair(0ll, 0ll)) return false;
  	if (x == make_pair(0ll, 0ll)) return true;
    bool a = x < make_pair(0ll, 0ll), b = y < make_pair(0ll, 0ll);
    if (a != b) return a < b;
    return x.first * y.second < x.second * y.first;
}

int main() {
    ios::sync_with_stdio(false);
    int n;
    ll z = 0;
    pair<ll, ll> a[213] = {};
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;
    sort(a, a + n, cmp);
    for (int i = 0; i < n; i++) a[i + n] = a[i];
    for (int i = 0; i < n; i++) {
        ll x = 0, y = 0;
        for (int j = i; j < i + n; j++) {
            x += a[j].first;
            y += a[j].second;
            z = max(z, x * x + y * y);
        }
    }
    cout << setprecision(17) << sqrt(z) << '\n';
}

