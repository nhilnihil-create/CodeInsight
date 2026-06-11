#include <bits/stdc++.h>

#define EPS (1e-10)
#define rep(i, a, b) for (int i = a; i < (int)(b); ++i)
#define rrep(i, a, b) for (int i = b - 1; i >= (int)(a); --i)
#define all(a) a.begin(), a.end()

using namespace std;
using ll = long long;
using vi = vector<int>;
using vb = vector<bool>;
using vll = vector<ll>;
using vd = vector<double>;
using vvi = vector<vi>;
using vvb = vector<vb>;

constexpr int MOD = 1000000007;
constexpr int TMAX = 3000;

struct Dish {
    int t, p;
    Dish(int t = 0, int p = 0) : t(t), p(p) {}
    Dish(const Dish& d) : t(d.t), p(d.p) {}

    bool operator<(const Dish& d) const { return (t != d.t ? t < d.t : p > d.p); }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, t;
    cin >> n >> t;

    vector<Dish> in(n);
    rep(i, 0, n) { cin >> in[i].t >> in[i].p; }

    // Sort based on t.
    sort(all(in));

    vi dp(t, 0);
    int ans = 0;

    rep(i, 0, n) {
        ans = max(ans, dp.back() + in[i].p);
        rrep(j, in[i].t, t) { dp[j] = max(dp[j], dp[j - in[i].t] + in[i].p); }
    }

    cout << ans << endl;
    return 0;
}