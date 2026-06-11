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
const double EPS = 1e-10;
const double PI  = acos(-1.0);
const ll MOD = 1000000007;
// const ll MOD = 998244353;
const int INF = 1 << 30;
// const ll INF = 1LL << 62;
// --------------------------------------------------------


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(10);

    int N, K; cin >> N >> K;

    int MAX_K = (N - 1) * (N - 2) / 2;
    if (K > MAX_K) {
        cout << -1 << '\n';
        return 0;
    }

    VP E;
    FOR(i, 1, N) E.push_back(make_pair(i, N));
    bool is_end = false;
    int num = MAX_K;
    FOR(i, 1, N - 1) {
        if (is_end) break;
        FOR(j, i + 1, N) {
            if (num == K) {
                is_end = true;
                break;
            }
            num--;
            E.push_back(make_pair(i, j));
        }
    }

    int M = SZ(E);
    cout << M << '\n';
    for (auto uv : E) {
        cout << uv.first << " " << uv.second << '\n';
    }

    return 0;
}
