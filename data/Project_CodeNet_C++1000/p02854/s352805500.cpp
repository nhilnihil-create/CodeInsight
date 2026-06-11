#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll INF = 1'010'000'000'000'000'017LL;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()

int main() {
    // AtCoder
    // template
    ll n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    vector<ll> sum(1, 0);
    rep(i, n) { sum.push_back(sum[i] + a[i]); }

    ll mi = INF;
    for(size_t i = 1; i < n; i++) {
        mi = min(mi, abs(sum[i] - (sum[n] - sum[i])));
    }
    cout << mi << endl;
}
