#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// --------------------------------------------------------
#define FOR(i,l,r) for (int i = (l); i < (r); ++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(c) (c).begin(), (c).end()
#define RALL(c) (c).rbegin(), (c).rend()
#define SORT(c) sort(ALL(c))
#define RSORT(c) sort(RALL(c))
#define MIN(c) *min_element(ALL(c))
#define MAX(c) *max_element(ALL(c))
#define SUM(c) accumulate(ALL(c), 0)
#define SUMLL(c) accumulate(ALL(c), 0LL)
#define SZ(c) ((int)(c).size())
#define debug(x) cerr << #x << " = " << (x) << '\n';
using P = pair<int,int>;
using VP = vector<P>;
using VVP = vector<VP>;
using VS = vector<string>;
using VI = vector<int>;
using VVI = vector<VI>;
using VLL = vector<ll>;
using VVLL = vector<VLL>;
using VB = vector<bool>;
using VVB = vector<VB>;
using VD = vector<double>;
using VVD = vector<VD>;
const double EPS = 1e-10;
const double PI  = acos(-1.0);
const ll MOD = 1000000007;
// const ll MOD = 998244353;
const int INF = 1 << 30;
// const ll INF = 1LL << 62;
// --------------------------------------------------------


double dist(int x1, int y1, int x2, int y2) {
    double dx = x1 - x2;
    double dy = y1 - y2;
    return pow(dx * dx + dy * dy, 0.5);
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(10);

    int N; cin >> N;
    VI X(N), Y(N); REP(i,N) cin >> X[i] >> Y[i];

    double ans = 0.0;
    int num = 0;
    VI P(N); iota(ALL(P), 0);
    do {
        FOR(i, 0, N - 1) {
            int p1 = P[i], p2 = P[i + 1];
            ans += dist(X[p1], Y[p1], X[p2], Y[p2]);
        }
        num++;
    } while (next_permutation(ALL(P)));

    ans /= num;
    cout << ans << '\n';

    return 0;
}
