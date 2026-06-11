#include <bits/stdc++.h>
using namespace std;

inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> P;
typedef long long ll;

#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define SORT(c) sort((c).begin(),(c).end())
#define REVERSE(c) reverse((c).begin(),(c).end())

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

const double EPS = 1e-10;
const double PI  = acos(-1.0);
const int INT_INF = 2147483647;
const long long LL_INF = 1LL<<60;
const long long MOD = 1000000007;

#define CLR(a) memset((a), 0 ,sizeof(a))

#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

int main(void){
    ll N,K; cin >> N >> K;
    vector<ll> A(N); REP(i,N) cin >> A[i];
    vector<ll> S1(N+1), S2(N+1); S1[0] = 0; S2[0] = 0;
    REP(i,N){
        S1[i+1] = S1[i] + A[i];
        S2[i+1] = (S1[i+1] - (i+1)) % K;
    }

    map<ll,ll> m;
    REP(i,min(N+1,K)){
        if(m.find(S2[i]) == m.end()) m[S2[i]] = 1;
        else m[S2[i]]++;
    }

    ll ans = 0;
    for(auto p : m){
        ans += p.second * (p.second-1) / 2;
    }

    FOR(i,K,N+1){
        if(m[S2[i-K]]) m[S2[i-K]]--;
        else m.erase(m[S2[i-K]]);
        if(m.find(S2[i]) != m.end()) ans += m[S2[i]]++;
        else m[S2[i]] = 1;
    }
    cout << ans << endl;
    return 0;
}