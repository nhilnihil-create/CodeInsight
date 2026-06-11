#include <bits/stdc++.h>
using namespace std;

inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int,int,int> tpl;

#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define SORT(c) sort((c).begin(),(c).end())
#define REVERSE(c) reverse((c).begin(),(c).end())

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define RFOR(i,a,b) for(int i=(a)-1;i>=(b);--i)
#define RREP(i,n) RFOR(i,n,0)

const double EPS = 1e-9;
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
    int N; cin >> N;
    VI A(N); REP(i,N) cin >> A[i];
    SORT(A);
    int p = 0, n = 0;
    REP(i,N){
        if(A[i] < 0) n++;
        else p++;
    }
    vector<P> ans;
    int M;
    if(n == 0){
        int x = A[0], y;
        REP(i,p-2){
            y = A[i+1];
            ans.emplace_back(x,y);
            x -= y;
        }
        y = x;
        x = A[N-1];
        ans.emplace_back(x,y);
        M = x - y;
    }
    else if(p == 0){
        int x = A[N-1], y;
        REP(i,n-1){
            y = A[i];
            ans.emplace_back(x,y);
            x -= y;
        }
        M = x;
    }
    else{
        int x = A[0], y;
        REP(i,p-1){
            y = A[n+i];
            ans.emplace_back(x,y);
            x -= y;
        }
        y = x;
        x = A[N-1];
        ans.emplace_back(x,y);
        x -= y;
        REP(i,n-1){
            y = A[i+1];
            ans.emplace_back(x,y);
            x -= y;
        }
        M = x;
    }
    cout << M << endl;
    REP(i,N-1) cout << ans[i].first << " " << ans[i].second << endl;
    return 0;
}