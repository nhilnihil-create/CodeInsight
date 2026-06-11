#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
//cout << setprecision(20) << 

bool is_ok(ll value, ll limit, vector<ll> &a) {
    ll count = 0;
    for (auto i: a) {
        if (i <= value) continue;
        count += floor((double)i / value);
        if (count > limit) return false;
    }
    return true;
}

ll binarySearch(ll left, ll right, ll limit, vector<ll> &a) {
    ll mid = (left + right) / 2;
    while (right - left > 1) {
        if (is_ok(mid, limit, a)) {
            right = mid;
        }
        else {
            left = mid;
        }
        mid = (left + right) / 2;
    }
    return right;
}

int main() {
    ll n, k; cin >> n >> k;
    vector<ll> a(n);
    ll maxSize = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        maxSize = max(maxSize, a[i]);
    }
    cout << binarySearch(0, maxSize, k, a) << endl;
}