#include <bits/stdc++.h>
using namespace std;

#define REP(i, m, n) for (int i = (m); i < (int)(n); i++)
#define REPS(i, m, n) for (int i = (m); i <= (int)(n); i++)
#define rep(i, n) REP(i, 0, n)
#define reps(i, n) for (int i = 0; i <= (int)(n); i++)
#define rrep(i, x) for (int i = ((int)(x)-1); i >= 0; i--)
#define rreps(i, x) for (int i = (int)(x); i >= 0; i--)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef pair<int, int> P;
const int inf = INT_MAX;
const ll INF = 1LL << 60;
const ll mod = 1e9 + 7;
const double EPS = 1e-10;
const double PI = acos(-1.0);
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<typename A, size_t N, typename T> void Fill(A (&array)[N], const T &val) { fill( (T*)array, (T*)(array+N), val ); }
template <class T1, class T2, class Pred = std::less<T2> >
struct sort_pair_second {
    bool operator()(const std::pair<T1,T2>&left, const std::pair<T1,T2>&right) {
        Pred p;
        return p(left.second, right.second);
    }
};

int N, M, Q;
vector<ll> a, b, c, d;
ll ans = 0;

void dfs(vector<ll> v) {
    ll sn = 1;
    if (v.size() != 0) sn = v.back();
    if (v.size() == N) {
        ll score = 0;
        rep(j, Q) {
            if (v[b[j]-1] - v[a[j]-1] == c[j]) {
                score += d[j];
            }
        }
        ans = max(ans, score);
        return;
    }
    REPS(i, sn, M) {
        vector<ll> tmp = v;
        tmp.pb(i);
        dfs(tmp);
    }
    return;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N >> M >> Q;
    a.resize(Q);
    b.resize(Q);
    c.resize(Q);
    d.resize(Q);
    rep(i, Q) cin >> a[i] >> b[i] >> c[i] >> d[i];

    dfs(vector<ll> {});

    cout << ans << endl;
    return 0;
}