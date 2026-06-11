#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)

template<typename T> struct cusum {
    int n;
    vector<T> s;
    cusum(vector<T> &a) {
        n = a.size();
        s.resize(n + 1);
        s[0] = 0;
        for (int i = 1; i <= n; i++) {
            s[i] = s[i - 1] + a[i - 1];
        }
    }
    T sum(int a, int b) { // 半開区間[a,b)の和(0-indexed)
        return s[b] - s[a];
    }
};

int main() {
    int n;
    cin >> n;
    char s[n];
    rep(i, n) {
        cin >> s[i];
    }
    vector<int> r(n+1), w(n+1);
    rep(i, n+1) {
        if (i == 0) {
            r[i] = 0;
            w[i] = 0;
        } else {
            r[i] = r[i-1];
            w[i] = w[i-1];
            if (s[i-1] == 'R') r[i]++;
            else if (s[i-1] == 'W') w[i]++;
        }
    }
    int ans = 2e6;
    rep(i, n+1) {
        int x = w[i] - w[0];
        int y = r[n] - r[i];
        ans = min(ans, max(x, y));
    }
    cout << ans << endl;
}