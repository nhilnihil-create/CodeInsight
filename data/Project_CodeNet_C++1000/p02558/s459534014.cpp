#include <bits/stdc++.h>

#include <atcoder/dsu>
#define rep(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define reps(i, n) for (int i = 1, i##_len = (n); i <= i##_len; ++i)
#define rrep(i, n) for (int i = ((int)(n)-1); i >= 0; --i)
#define rreps(i, n) for (int i = ((int)(n)); i > 0; --i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define repc2(i, s, n) for (int i = (s); i <= (int)(n); i++)
#define inf 2e9
#define linf 9000000000000000000ll
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
using namespace atcoder;

int n, q;

int main() {
    cin >> n >> q;
    dsu ds(n);
    rep(i, q) {
        int t, u, v;
        cin >> t >> u >> v;
        if (t == 0) {
            ds.merge(u, v);
        } else {
            cout << ds.same(u, v) << endl;
        }
    }
    return 0;
}