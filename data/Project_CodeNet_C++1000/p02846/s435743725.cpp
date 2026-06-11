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
const int INT_INF = 2147483647;
const long long LL_INF = 1LL<<60;
const long long MOD = 1000000007; // 998244353

#define CLR(a) memset((a), 0, sizeof(a))

#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

int main(void){
    ll T1,T2; cin >> T1 >> T2;
    ll A1, A2; cin >> A1 >> A2;
    ll B1, B2; cin >> B1 >> B2;
    if(A1 < B1 && A1*T1+A2*T2 < B1*T1+B2*T2){
        cout << 0 << endl;
        return 0;
    }
    if(A1 > B1 && A1*T1+A2*T2 > B1*T1+B2*T2){
        cout << 0 << endl;
        return 0;
    }
    if(A1*T1+A2*T2 == B1*T1+B2*T2){
        cout << "infinity" << endl;
        return 0;
    }

    if(B1 > A1){
        swap(A1,B1);
        swap(A2,B2);
    }
    ll s = (B1-A1)*T1 + (B2-A2)*T2;
    ll ans = (A1-B1)*T1/s + (B2-A2)*T2/s;
    if((B2-A2)*T2%s == 0) ans--;
    cout << ans << endl;

    return 0;
}