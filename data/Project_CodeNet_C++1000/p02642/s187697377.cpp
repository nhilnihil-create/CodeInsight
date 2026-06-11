#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)

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
    vector<bool> b(1000001, true);
    for (int x : s) {
        for (int i = x + x; i <= 1000000; i += x) {
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
