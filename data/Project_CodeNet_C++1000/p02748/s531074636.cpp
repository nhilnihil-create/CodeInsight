#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; ++i)
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define ALL(vec) vec.begin(), vec.end()
#define rALL(vec) vec.rbegin(), vec.rend()
using namespace std;
using ll = long long;

int main() {
    int A, B, M;
    cin >> A >> B >> M;
    vector<int> a(A), b(B);
    int min_a = 1000000;
    int min_b = 1000000;
    rep(i, A) {
        cin >> a[i];
        min_a = min(min_a, a[i]);
    }
    rep(i, B) {
        cin >> b[i];
        min_b = min(min_b, b[i]);
    }
    int ans = min_a + min_b;
    rep(i, M) {
        int x, y, c;
        cin >> x >> y >> c;
        if (a[x - 1] + b[y - 1] - c < ans) ans = a[x - 1] + b[y - 1] - c;
    }
    cout << ans << endl;
    return 0;
}