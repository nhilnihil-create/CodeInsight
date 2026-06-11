#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define REP(i, n) for(int i = 0; i < (n); ++i)
#define REPr(i, n) for(int i = (n)-1; i >= 0; --i)
#define FORq(i, m, n) for(int i = (m); i <= (n); ++i)
#define FORqr(i, m, n) for(int i = (n); i >= (m); --i)
#define MP make_pair
#define SIN(x, S) (S.count(x) != 0)
#define M0(x) memset(x, 0, sizeof(x))
#define FILL(x, y) memset(x, y, sizeof(x))
#define MM(x) memset(x, -1, sizeof(x))
#define ALL(x) (x).begin(), (x).end()
#define DB(x) cerr << #x << " = " << x << endl
#define DB2(x, y)                                                              \
    cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n";
#define DEBUG                                                                  \
    int x12345;                                                                \
    cin >> x12345;
typedef pair<int, int> PII;
typedef pair<long long, long long> PLL;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<long long> VL;
typedef long long ll;
typedef long long integer;
const long long MOD = 1e9 + 7;
///////////////////////////////////////////////
// for template
template <class T> inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}
template <class T> inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}
///////////////////////////////////////////////
/// 🍈( '-' 🍈 |AC|
int main() {
    ll N,K; cin >> N >> K;
    vector<int> P(N);
    vector<ll> C(N);
    REP(i,N){
        cin >> P[i];
        P[i]--;
    }
    REP(i,N){
        cin >> C[i];
    }

    ll ans = -1e16;

    REP(i,N){
        int pos = i;
        ll cyclesum = 0;
        ll cyclesize = 0;
        while(true){
            cyclesize++;
            cyclesum += C[pos];
            pos = P[pos];
            if (pos == i) break;
        }

        pos = i;
        ll cnt = 0;
        ll pathsum = 0;
        while(true){
            cnt++;
            pathsum += C[pos];
            if (cnt > K) break;
            ll cyclecount = (K - cnt) / cyclesize;
            ll nans = pathsum + max(0LL,cyclesum) * cyclecount;
            pos = P[pos];
            chmax(ans, nans);
            if (pos == i) break;
        }
    }
    cout << ans << endl;
}   