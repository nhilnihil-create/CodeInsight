#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i<(n); i++)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
using namespace std;
using ll = long long;

using P = pair<int, int>;

int main() {
    int N;
    cin >> N;
    vector<int> a(N);
    rep(i, N) cin >> a[i];

    vector<P> p(N);
    rep(i, N) {
        p[i].first = a[i];
        p[i].second = i;
    }

    sort(p.begin(), p.end());
    vector<int> minus_idx;
    vector<int> plus_idx;
    rep(i, p.size()) {
        int val = p[i].first;
        int idx = p[i].second;
        if (i == 0) {
            minus_idx.push_back(idx);
        } else if (i == N - 1) {
            plus_idx.push_back(idx);
        } else if (val >= 0) {
            plus_idx.push_back(idx);
        } else {
            minus_idx.push_back(idx);
        }
    }

    ll s = 0;
    rep(i, minus_idx.size()) s -= a[minus_idx[i]];
    rep(i, plus_idx.size()) s += a[plus_idx[i]];

    vector<P> op;
    int tmp = a[minus_idx[0]];
    for (int i = 1; i < plus_idx.size(); i++) {
        op.push_back(P{tmp, a[plus_idx[i]]});
        tmp -= a[plus_idx[i]];
    }
    int tmp2 = a[plus_idx[0]];
    for (int i = 1; i < minus_idx.size(); i++) {
        op.push_back(P{tmp2, a[minus_idx[i]]});
        tmp2 -= a[minus_idx[i]];
    }
    op.push_back(P{tmp2, tmp});

    cout << s << endl;
    rep(i, op.size()) cout << op[i].first << " " << op[i].second << endl;
}
