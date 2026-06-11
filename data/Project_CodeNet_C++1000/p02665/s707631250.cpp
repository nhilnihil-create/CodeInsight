#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

#define REPR(i,n) for(int i=(n); i >= 0; --i)
#define FOR(i, m, n) for(int i = (m); i < (n); ++i)
#define REP(i, n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define ALL(a)  (a).begin(),(a).end()
#define endl "\n"

template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return true; } return false; }
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
typedef long long ll;

void solve() {
    ll N;
    cin >> N;
    vector<ll> A(N+1);
    REP(i,N+1) cin >> A[i];

    // for corner
    if (N == 0) {
        if (A[0]==1) cout << 1 << endl;
        else cout << -1 << endl;
        return;
    }

    // for corner
    if (A[0] == 1) {
        cout << -1 << endl;
        return;
    }
    // その深さより↓の葉の数の合計
    vector<ll> dv(N+1,0);
    REPR(i,N-1) dv[i] = dv[i+1] + A[i+1];

    vector<ll> not_leaf_node(N+1,0);
    not_leaf_node[0] =1 ;
    ll ans = 1;
    FOR(i,1,N+1) {
        ll node = min(not_leaf_node[i-1] * 2,dv[i]+A[i]);
        if (node - A[i] < 0 ) {
            cout << -1 << endl;
            return;
        }
        not_leaf_node[i] = node - A[i];
        ans += node;
    }
    cout << ans << endl;
}

int main() {
    solve();
    return 0;
}
