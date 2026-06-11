#include <bits/stdc++.h>

#define FOR(i,a,b) for (int i=(a);i<(b);++i)
#define REP(i,n) for (int i=0;i<(n);++i)
#define all(a) (a).begin(),(a).end()

using namespace std;

using ll = long long;

ll solve() {

    int N;
    cin >> N;
    vector<int> A(N + 1);
    REP(i, N + 1) cin >> A[i];

    if (N == 0) {
        return A[0] == 1 ? 1 : -1;
    }

    if (A[0] > 0) {
        return -1;
    }

    ll n_leaves = accumulate(all(A), 0ll);
    if (n_leaves == 0) {
        return -1;
    }

    ll result = 1;

    ll k = 1; // number of vertices that are not leaves and in depth d.

    FOR(d, 1, N + 1) {
        ll n_children = min(n_leaves, 2 * k);
        if (n_children < A[d]) {
            return -1;
        }
        result += n_children;
        n_leaves -= A[d];
        k = n_children - A[d];
    }

    return result;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
