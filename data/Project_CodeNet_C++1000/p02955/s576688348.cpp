#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using P = pair<int, int>;
using vec = vector<lint>;
using mat = vector<vector<int>>;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define endl "\n"

constexpr int MOD = 1000000007;
const int INF = 1 << 30;

int main() {
    int n, k;
    cin >> n >> k;
    vec a(n);
    rep(i, n) cin >> a[i];

    lint asum = accumulate(all(a), 0LL);

    vec div;
    for (lint i = 1; i * i <= asum; i++) {
        if (asum % i == 0) {
            div.push_back(i);
            if (i * i != asum) div.push_back(asum/i);
        }
    }

    sort(all(div), greater<lint>());

    lint res = 1;

    for (auto&& d : div) {
        vec r(n);
        rep(i, n) r[i] = a[i] % d;

        sort(all(r));

        vec L(n+1), R(n+1);
        rep(i, n) L[i+1] = L[i] + r[i];
        for (int i = n-1; i >= 0; --i) {
            R[i] = R[i+1] + (d - r[i]);
        }

        for (int i = 0; i <= n; i++) {
            if (L[i] == R[i] && L[i] <= k) {
                res = max(res, d);
                break;
            }
        }
    }

    cout << res << endl;
    return 0;
}