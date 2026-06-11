#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0, i##_len = (int)(n); i < i##_len; i++)
#define reps(i, n) for (int i = 1, i##_len = (int)(n); i <= i##_len; i++)
#define ALL(v) (v).begin(), (v).end()
const auto MOD = 998244353;
int main() {
    int n;
    cin >> n;
    auto counts = vector<int>(n, 0);
    int c;
    cin >> c;
    if (c != 0) {
        cout << 0 << endl;
        return 0;
    }
    counts[0] = 1;
    rep(i, n - 1) {
        int d;
        cin >> d;
        counts[d]++;
    }
    auto iterator = counts.end();
    iterator--;
    while (*iterator == 0) {
        counts.erase(iterator);
        iterator = counts.end();
        iterator--;
    }
    if (counts[0] > 1 || count(ALL(counts), 0) > 0) {
        cout << 0 << endl;
        return 0;
    }
    long long ans = 1;
    reps(i, counts.size() - 1) {
        auto x = counts[i - 1];
        auto y = counts[i];
        rep(j, y) {
            ans *= x;
            ans %= MOD;
        }
    }
    cout << ans << endl;
    return 0;
}
