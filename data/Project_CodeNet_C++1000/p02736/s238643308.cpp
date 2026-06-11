#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef tuple<ll, ll, ll> iii;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
#define REP(i,n) for (ll i = 0; i < n; ++i)
#define REPR(i,n) for (ll i = n-1; i >= 0; --i)
#define FOR(i,m,n) for (ll i = m; i < n; ++i)
#define FORR(i,m,n) for (ll i = n-1; i >= m; --i)
#define FORE(x,xs) for (const auto& x : xs)
#define ALL(v) v.begin(), v.end()
#define CHMIN(x,y) x = min(x, y)
#define CHMAX(x,y) x = max(x, y)

int N;
string A;

int lucas(int m, int n) {
    int comb[2][2] = {{1, 0}, {1, 1}};
    int ret = 1;
    while (m) {
        int m_ = m%2, n_ = n%2;
        ret *= comb[m_][n_];
        m /= 2; n /= 2;
    }
    return ret;
}

int sub(int b) {
    int ret = 0;
    REP (i, N) {
        int x = (A[i] - '1') >> b;
        ret += lucas(N-1, i) * x;
    }
    return ret % 2;
}

int solve() {
    if (sub(0)) return 1;
    REP (i, N) if (A[i] == '2') return 0;
    return sub(1) * 2;
}

int main() {
    cin >> N >> A;
    cout << solve() << endl;
}