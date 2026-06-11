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

    int N; cin >> N;
    string S; cin >> S;

    int ans = 0;
    for (char c1 = '0'; c1 <= '9'; c1++) {
        for (char c2 = '0'; c2 <= '9'; c2++) {
            set<char> T;
            int d = 1;
            for (auto s : S) {
                if (d == 1) {
                    if (s == c1) d++;
                } else if (d == 2) {
                    if (s == c2) d++;
                } else {
                    T.insert(s);
                }
            }
            ans += SZ(T);
        }
    }
    cout << ans << '\n';

    return 0;
}
