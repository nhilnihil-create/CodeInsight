#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P  = pair<int, int>;
int main() {
    int res = 0, n;
    string s;
    cin >> n >> s;
    for (int p = n; p > 0; --p) {
        vector<int> a(n, 0);
        a[0]  = p;
        int i = 1, j = 0;
        while (i < n) {
            while (i + j < p && s[j + n - p] == s[i + j + n - p]) ++j;
            a[i] = j;
            if (!j) {
                ++i;
                continue;
            }
            int k = 1;
            while (i + k < n && k + a[k] < j) a[i + k] = a[k], ++k;
            i += k;
            j -= k;
        }
        for (int q = 0; q < p; ++q) {
            if (q >= a[q]) res = max(res, a[q]);
        }
    }
    cout << res;
    return 0;
}