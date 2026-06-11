#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define FOR(i, a, b) for (int i = (a); i <= (int)(b); ++i)
#define FORR(i, a, b) for (int i = (a); i >= (int)(b); --i)
#define ALL(c) (c).begin(), (c).end()

typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<VI> VVI;
typedef vector<VL> VVL;
typedef pair<int, int> P;
typedef pair<ll, ll> PL;
typedef vector<P> VP;
typedef vector<PL> VPL;
typedef vector<string> VS;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    VI a(n + 1);  // 1-indexed
    REP(i, n) cin >> a[i + 1];
    VI ball_sum(n + 1, 0);
    VVI factors(n + 1);
    FOR(i, 1, n) { FOR(j, 1, n / i) factors[i * j].push_back(i); }
    VI ans;
    FORR(i, n, 1) {
        if (ball_sum[i] % 2 != a[i]) {
            for (auto& f : factors[i]) ball_sum[f]++;
            ans.push_back(i);
        }
    }

    cout << ans.size() << ln;
    REP(i, ans.size()) {
        if (i == (int)ans.size() - 1)
            cout << ans[i] << ln;
        else
            cout << ans[i] << " ";
    }
    return 0;
}
