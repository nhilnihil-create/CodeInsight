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
    int N; cin >> N;
    vector<ll> leaf(N+2);
    vector<ll> unleaf(N+2);
    ll leafall = 0;

    REP(i,N + 1){
        cin >> leaf[i];
        leafall += leaf[i];
    }


    if (N == 0){
        if (leaf[0] == 1) cout << 1 << endl;
        else cout << -1 << endl;
        return 0;
    }

    
    ll ans = 0;
    ll all = 1;
    ll allp = 0;
    REP(i,N + 1){
        leafall -= leaf[i];
        if (i == 0) unleaf[i] = all - leaf[i];
        else unleaf[i] = min(leafall, unleaf[i - 1] * 2 - leaf[i]);
        if (unleaf[i] < 0){
            cout << -1 << endl;
            return 0;
        }
    }

    REP(i,N+1){
        //DB2(leaf[i],unleaf[i]);
        ans += leaf[i] + unleaf[i];
    }
    cout << ans << endl;
}