#include <bits/stdc++.h>

#include <atcoder/all>
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
using namespace atcoder;
using ll = long long;
using P = pair<int, int>;

class Main {
    int N, Q;
    vector<ll> a;
    void input() {
        cin >> N >> Q;
        a.resize(N);
        REP(i, N) { cin >> a[i]; }
    }
    void output() {
        fenwick_tree<ll> fw(N);
        REP(i, N) { fw.add(i, a[i]); }
        REP(q, Q) {
            int a, b, c;
            cin >> a >> b >> c;
            if (a == 0) {
                fw.add(b, c);
            } else {
                cout << fw.sum(b, c) << endl;
            }
        }
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
