#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define int long long

template <class T>
bool INRANGE(T x, T a, T b) { return a <= x && x <= b; }
template <class T>
inline bool chmin(T &a, T b)
{
    if (a > b)
    {
        a = b;
        return true;
    }
    return false;
}
template <class T>
inline bool chmax(T &a, T b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
    return false;
}

#define REP(i, n) for (int i = 0; i < (n); ++i)
#define RREP(i, n) for (int i = (n); i >= 0; --i)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define RFOR(i, a, b) for (int i = (a); i >= (b); --i)
#define ALL(v) (v).begin(), (v).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" \
                      << " " << __FILE__ << endl;

typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<vi> vvi;
typedef pair<int, int> pii;

signed main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    vector<pii> pi(N);
    REP(i, N) {
        int a;
        cin >> a;
        pi[i] = make_pair(a, i);
    }
    
    sort(ALL(pi), greater<>());

    vvi dp(N+1, vi(N+1, 0));

    REP(i, N) REP(j, N-i) {
        chmax(dp[i+1][j], dp[i][j] + pi[i+j].first*(pi[i+j].second-i)); //left
        chmax(dp[i][j+1], dp[i][j] + pi[i+j].first*((N-1-j)-pi[i+j].second)); //right
    }

    int ans = 0;
    REP(i, N) ans = max(ans, dp[i][N-i]);

    cout << ans << endl;

    return 0;
}
