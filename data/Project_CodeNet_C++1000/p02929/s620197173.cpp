#include <bits/stdc++.h>
using namespace std;

inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}

typedef long long ll;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<long long> VL;
typedef vector<vector<long long>> VVL;
typedef vector<string> VS;
typedef pair<int, int> P;
typedef tuple<int,int,int> tpl;

#define ALL(a)  (a).begin(),(a).end()
#define SORT(c) sort((c).begin(),(c).end())
#define REVERSE(c) reverse((c).begin(),(c).end())
#define LB(a,x) lower_bound((a).begin(), (a).end(), x) - (a).begin()
#define UB(a,x) upper_bound((a).begin(), (a).end(), x) - (a).begin()

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define RFOR(i,a,b) for(int i=(a)-1;i>=(b);--i)
#define RREP(i,n) RFOR(i,n,0)

#define en "\n"

constexpr double EPS = 1e-9;
constexpr double PI  = 3.141592653589793238462643383279;
constexpr int INF = 2147483647;
constexpr long long LINF = 1LL<<60;
constexpr long long MOD = 1000000007; // 998244353

#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

int main(void){
    int N; cin >> N; N <<= 1;
    string S; cin >> S;
    if(S[0]=='W' || S.back()=='W'){
        cout << 0 << endl;
        return 0;
    }

    VI d(N,0); d[0] = 1;
    REP(i,N-1) if(S[i+1]==S[i]) d[i+1] = d[i]^1; else d[i+1] = d[i];
    VL f(N,0); int nl = 0, nr = 0;
    REP(i,N){
        if(d[i] == 1) nl++;
        else{
            f[i] = max(0,nl-nr);
            nr++;
        }
    }
    if(nl != nr){
        cout << 0 << endl;
        return 0;
    }
    ll ans = 1;
    REP(i,N) if(d[i]==0) (ans *= f[i]) %= MOD;
    REP(i,N/2) (ans *= i+1) %= MOD;
    cout << ans << endl;
    return 0;
}