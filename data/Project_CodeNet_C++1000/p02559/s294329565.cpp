#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for(int i = 0; i < (n); ++i)

void solve() {
    int N, Q;
    cin >> N >> Q;
    fenwick_tree<int64_t> fw(N);
    rep(i, N) {
        int a; cin >> a;
        fw.add(i, a);
    }
    while(Q--) {
        int t, a, b;
        cin >> t >> a >> b;
        if(!t) fw.add(a, b);
        else cout << fw.sum(a, b) << '\n';
    }

}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
}
