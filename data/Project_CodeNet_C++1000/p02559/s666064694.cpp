#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;
using namespace atcoder;

typedef long long ll;
typedef long double Double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

// chmax, chmin
template<class T>
inline bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}

template<class T>
inline bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return 1;
    }
    return 0;
}

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<int> a(N);
    for (int i = 0; i < N; i++)
        cin >> a[i];

    auto c = fenwick_tree<ll>(N);
    for(int i = 0 ; i < N ; i++)
        c.add(i, a[i]);
    for (int i = 0; i < Q; i++) {
        int t;
        cin >> t;
        if (t == 0) {
            int p, x;
            cin >> p >> x;
            c.add(p, x);
        } else {
            int l, r;
            cin >> l >> r;
            cout << c.sum(l, r) << endl;
        }
    }
    // Failed to predict input format
    return 0;
}
