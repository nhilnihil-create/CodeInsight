#include <bits/stdc++.h>
#include <atcoder/all>
#define REP(i,n) for(int i=0; i<(int)(n); ++i)
using namespace std;
using namespace atcoder;
typedef long long LL;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
inline bool valid(int x, int w) { return 0 <= x && x < w; }

void iostream_init() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.setf(ios::fixed);
    cout.precision(12);
}

int main(){
    iostream_init();

    int N, Q;
    cin >> N >> Q;
    dsu d(N);
    REP(i, Q) {
        int t, u, v;
        cin >> t >> u >> v;
        if (t == 0) {
            d.merge(u, v);
        } else {
            cout << (d.same(u, v) ? 1 : 0) << endl;
        }
    }
    return 0;
}
