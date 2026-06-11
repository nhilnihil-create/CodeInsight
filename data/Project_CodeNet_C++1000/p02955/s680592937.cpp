#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(v) (v).begin(), (v).end()
using ll = long long;
constexpr int INF = 1e9;
constexpr long long LINF = 1e18;
constexpr long long MOD = 1e9 + 7;

vector<long long> divisor(long long n) {
    vector<long long> res;
    for (int i = 1; (long long)i * i <= n; i++) {
        if (n % i == 0) {
            res.push_back(i);
            if (i != n / i) res.push_back(n / i);
        }
    }
    sort(begin(res), end(res));
    return res;
}

signed main() {
    int n, k;
    cin >> n >> k;
    int sum = 0;
    int a[n];
    rep(i, n) {
        cin >> a[i];
        sum += a[i];
    }
    auto D = divisor(sum);
    reverse(ALL(D));
    for (int d : D) {
        int r[n];
        rep(i, n) {
            r[i] = a[i] % d;
        }
        sort(r, r + n);
        int rr[n];
        rep(i, n) {
            rr[i] = d - r[i];
        }
        int sumrr[n + 1] = {};
        rep(i, n) {
            sumrr[i + 1] = sumrr[i] + rr[i];
        }
        int sumr = 0;
        rep(i, n) {
            sumr += r[i];
            if (sumr == sumrr[n] - sumrr[i + 1]) break;
        }
        if (sumr <= k) {
            cout << d << endl;
            return 0;
        }
    }
    return 0;
}