#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)

template<typename T> T prime_fact(T x, vector<
T> &factor) { // 素因数分解（返り値はxの正の約数の個数）
    T r = 1;
    for (T i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            T cnt = 1;
            while (x % i == 0) {
                factor.push_back(i);
                x /= i;
                cnt++;
            }
            r *= cnt;
        }
    }
    if (x != 1) {
        factor.push_back(x);
        r *= 2;
    }
    return r;
}

int main() {
	int n;
    cin >> n;
    vector<int> a(n);
    map<int, bool> m;
    set<int> s;
    rep(i, n) {
        cin >> a[i];
        if (s.count(a[i])) {
            m[a[i]] = true;
        } else {
            s.insert(a[i]);
        }
    }
    const int _n = 1e6;
    vector<bool> b(_n+1, true);
    for (int x : s) {
        for (int i = x + x; i <= _n; i += x) {
            b[i] = false;
        }
    }
    int cnt = 0;
    rep(i, n) {
        if (m[a[i]]) {
            continue;
        }
        if (b[a[i]]) {
            cnt++;
        }
    }
    cout << cnt << endl;
}
