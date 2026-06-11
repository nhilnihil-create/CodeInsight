#include <bits/stdc++.h>
using namespace std;
#define Int int64_t
#define dump(x) cout << (x) << endl
#define fi first
#define se second
Int mod = 1e9+7;
//Int mod = 998244353;
Int INF = 1e18;
double EPS = 0.00000001;

int main() {
    Int n;
    string s;
    cin >> n >> s;
    if (s.front() == 'W' || s.back() == 'W') {
        dump(0);
        return 0;
    }
    Int cnt = 0;
    for (Int i = 0; i < 2 * n; i++) {
        if (s[i] == 'W') cnt++;
    }
    if (cnt % 2 == 1) {
        dump(0);
        return 0;
    }
    vector<char> d(2 * n);
    d[0] = 'L';
    for (Int i = 0; i < 2 * n - 1; i++) {
        if (s[i] == s[i + 1]) {
            d[i + 1] = d[i] == 'L' ? 'R' : 'L';
        }
        else {
            d[i + 1] = d[i] == 'R' ? 'R' : 'L';
        }
    }
    Int res = 0;
    Int r = 0;
    Int add = 1;
    for (Int i = 2 * n - 1; i >= 0; i--) {
        if (d[i] == 'R') {
            r++;
        }
        else {
            add = (add * r) % mod;
            r--;
        }
    }
    if (r != 0) {
        dump(0);
        return 0;
    }
    res += add;
    res %= mod;
    for (Int i = 1; i <= n; i++) {
        res = (res * i) % mod;
    }
    dump(res % mod);
    return 0;
}