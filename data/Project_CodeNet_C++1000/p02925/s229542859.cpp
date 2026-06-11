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
    VVI A(N,VI(N-1)); REP(i,N)REP(j,N-1){cin >> A[i][j]; A[i][j]--;}
    map<P,int> m;
    int t = 0;
    REP(i,N-1)FOR(j,i+1,N){
        m[P(i,j)] = t++;
    }

    VI deg(N*(N-1),0);
    VI edge[N*(N-1)];
    REP(i,N)REP(j,N-2){
        edge[m[P(min(i,A[i][j]),max(i,A[i][j]))]].push_back(m[P(min(i,A[i][j+1]), max(i,A[i][j+1]))]);
        deg[m[P(min(i,A[i][j+1]), max(i,A[i][j+1]))]]++;
    }

    queue<int> q;
    REP(i,N*(N-1)){
        if(deg[i] == 0) q.push(i);
    }

    int day = 0;
    queue<int> q2;
    while(q.size()){
        day++;
        while(q.size()){
            for(int n : edge[q.front()]){
                deg[n]--;
                if(deg[n] == 0) q2.push(n);
            }
            q.pop();
        }
        if(q2.empty()) break;
        swap(q,q2);
    }
    REP(i,N*(N-1)){
        if(deg[i] ){
            cout << -1 << endl;
            return 0;
        }
    }
    cout << day << endl;
    return 0;
}