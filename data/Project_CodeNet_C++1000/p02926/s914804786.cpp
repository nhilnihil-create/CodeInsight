#include <bits/stdc++.h>
using namespace std;

inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef long long ll;
typedef pair<int, int> P;
typedef tuple<double,double,double> tpl;

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
    vector<tpl> ee(N);
    REP(i,N){
        double x,y; cin >> x >> y;
        double theta;
        if(x == 0 && y == 0) theta = 0;
        else theta = atan2(y,x);
        if(theta < 0) theta += 2*PI;
        get<0>(ee[i]) = theta;
        get<1>(ee[i]) = x;
        get<2>(ee[i]) = y;
    }
    SORT(ee);
    vector<tpl> e(2*N);
    REP(i,N){
        get<0>(e[i]) = get<0>(ee[i]);
        get<1>(e[i]) = get<1>(ee[i]);
        get<2>(e[i]) = get<2>(ee[i]);
        get<0>(e[i+N]) = get<0>(ee[i]) + 2*PI;
        get<1>(e[i+N]) = get<1>(ee[i]);
        get<2>(e[i+N]) = get<2>(ee[i]);
    }

    double ans = 0;
    REP(i,N)FOR(j,i,N){
        double x = 0, y = 0;
        FOR(k,i,j+1){
            x += get<1>(e[k]);
            y += get<2>(e[k]);
        }
        chmax(ans, sqrt(x*x+y*y));
        x = 0, y = 0;
        FOR(k,j+1,j+N-(j-i+1)){
            x += get<1>(e[k]);
            y += get<2>(e[k]);
        }
        chmax(ans, sqrt(x*x+y*y));
    }
    cout << fixed << setprecision(12) << ans << endl;
    return 0;
}