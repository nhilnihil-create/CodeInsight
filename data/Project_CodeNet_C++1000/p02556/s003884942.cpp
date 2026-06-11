#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < n; ++i)
#define REPR(i, n) for (int i = n - 1; i >= 0; --i)
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define FORR(i, a, b) for (int i = b - 1; i >= a; --i)
#define SORT(v) sort(v.begin(), v.end())
#define SORTR(v) sort(v.rbegin(), v.rend())
#define REV(v) reverse(v.begin(), v.end())
#define ITER(itr, v) for (auto itr = v.begin(); itr != v.end(); ++itr)
#define LB(v, x) (lower_bound(v.begin(), v.end(), x) - v.begin())
#define UB(v, x) (upper_bound(v.begin(), v.end(), x) - v.begin())
#define SZ(v) (int)v.size()
using namespace std;
using ll = long long;
using P = pair<int, int>;

class Main {
    int N;
    vector<ll> x, y;
    void input() {
        cin >> N;
        x.resize(N);
        y.resize(N);
        REP(i, N) { cin >> x[i] >> y[i]; }
    }
    void output() {
        vector<ll> z(N), w(N);
        REP(i, N) {
            z[i] = x[i] + y[i];
            w[i] = x[i] - y[i];
        }
        ll res =
            *max_element(z.begin(), z.end()) - *min_element(z.begin(), z.end());
        res = max(res, *max_element(w.begin(), w.end()) -
                           *min_element(w.begin(), w.end()));
        cout << res << endl;
    }

public:
    Main() {
        input();
        output();
    }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    Main();

    return 0;
}
