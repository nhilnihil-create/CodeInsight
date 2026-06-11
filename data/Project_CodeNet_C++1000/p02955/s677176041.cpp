#include <bits/stdc++.h>
using namespace std;

inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}

typedef long long ll;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> P;
typedef tuple<int,int,int> tpl;

#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define SORT(c) sort((c).begin(),(c).end())
#define REVERSE(c) reverse((c).begin(),(c).end())
#define LB(a,x) lower_bound((a).begin(), (a).end(), x) - (a).begin()
#define UB(a,x) upper_bound((a).begin(), (a).end(), x) - (a).begin()

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define RFOR(i,a,b) for(int i=(a)-1;i>=(b);--i)
#define RREP(i,n) RFOR(i,n,0)

#define en "\n"

const double EPS = 1e-9;
const double PI  = acos(-1.0);
const int INF = 2147483647;
const long long LINF = 1LL<<60;
const long long MOD = 1000000007; // 998244353

#define CLR(a) memset((a), 0, sizeof(a))

#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

vector<long long> make_divisors(long long n){
    vector<long long> divisors;
    for(long long i=1; i*i<=n; i++){
        if(n%i == 0){
            divisors.push_back(i);
            if(i*i != n) divisors.push_back(n/i);
        }
    }
    // sort(divisors.begin(), divisors.end());
    return divisors;
}

int main(void){
    int N,K; cin >> N >> K;
    VI A(N); REP(i,N) cin >> A[i];
    int S = 0; REP(i,N) S += A[i];
    auto v = make_divisors(S);
    SORT(v); REVERSE(v);
    int ans = 0;
    for(int q : v){
        VI B(A);
        REP(i,N) B[i] %= q;
        SORT(B);
        VI S1(N-1,0), S2(N-1,0);
        S1[0] = B[0]; REP(i,N-2) S1[i+1] = S1[i] + B[i+1];
        S2[N-2] = q-B[N-1]; REP(i,N-2) S2[N-3-i] = S2[N-2-i] + q - B[N-2-i];
        bool flag = false;
        REP(i,N-1){
            if(S1[i] <= K && S2[i] <= K && S1[i]%q==S2[i]%q) chmax(ans, q);
        }
    }
    cout << ans << endl;
    return 0;
}