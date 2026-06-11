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
    ll N, K; cin >> N >> K;
    vector<ll> A(N+2);
    FORq(i,1,N){
        cin >> A[i];
    }
    
    REP(i,min(48LL,K)){
        vector<ll> S(N+2),T(N+2);
        FORq(k,1,N){
            ll a = A[k];
            ll al = max(1LL,k - a);
            ll ar = min(N, k + a);
            S[al]++;
            S[ar + 1]--;
            //DB2(al,ar);
        }

        FORq(k,1,N){
            T[k] = T[k-1] + S[k];
        }

        FORq(j,1,N){
            A[j] = T[j];
        }
    }

    FORq(i,1,N){
        cout << A[i] << " ";
    }
    cout << endl;
}