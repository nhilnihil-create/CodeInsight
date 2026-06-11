//include
//------------------------------------------
#include <bits/stdc++.h>
using namespace std;
//conversion
//------------------------------------------
inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}
//math
//-------------------------------------------
template<class T> inline T sqr(T x) {return x*x;}
//typedef
//------------------------------------------
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> P;
typedef long long ll;
//container util
//------------------------------------------
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define MP make_pair
#define SZ(a) int((a).size())
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())
//repetition
//------------------------------------------
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
//constant
//--------------------------------------------
const double EPS = 1e-10;
const double PI  = acos(-1.0);
const long long INF = 1000000007;
//clear memory
#define CLR(a) memset((a), 0 ,sizeof(a))
//debug
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;
// chmax chmin
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
 
long long gcd(long long x, long long y){
    return x % y == 0 ? y : gcd(y, x%y);
}
 
ll lcm(ll a,ll b){
    ll g = gcd(a,b);
    return a / g * b; // Be careful not to overflow
}
 
int main(void){
    ll N,M; cin >> N >> M;
    ll a[N]; REP(i,N) cin >> a[i];
 
    ll fact = 2;
    while(a[0]%fact == 0){
        fact <<= 1;
    }
    fact >>= 1;
    bool flag = false;
    REP(i,N){
        if(a[i]%fact != 0 || a[i]%(2*fact) == 0){
            flag = true;
            break;
        }
    }
    if(flag){
        cout << 0 << endl;
        return 0;
    }
    
    REP(i,N) a[i] /= 2;
 
    ll l = 1;
    REP(i,N) l = lcm(l, a[i]);
    ll ans = M/l;
    if(ans % 2 == 0) ans = ans/2;
    else ans = ans/2 + 1;
    cout << ans << endl;
 
    return 0;
}