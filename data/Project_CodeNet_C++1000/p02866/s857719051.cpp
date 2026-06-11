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
//clear memory
#define CLR(a) memset((a), 0 ,sizeof(a))
//debug
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;
// chmax chmin
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
#define INF (ll)998244353
long long mul_modp(long long a, long long b, long long p){
    // a*b mod p
    return ((a % p) * (b % p)) % p;
}

long long pow_modp(long long a, long long n, long long p){
    // a^n mod p
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = mul_modp(res, a, p);
        a = mul_modp(a, a, p);
        n >>= 1;
    }
    return res;
}

int main(void){
    ll N;
    cin >> N;
    vector<ll> D(N);
    REP(i,N) cin >> D[i];

    if(D[0] != 0){cout << 0 << endl; return 0;}
    SORT(D);
    if(D[1] != 1){cout << 0 << endl; return 0;}

    ll ans = 1, prev = 1, n = 0;
    auto itr = D.begin();
    while(itr!=D.end()){
        ll num = 0;
        while(itr!=D.end() && *itr == n){itr++; num++;}
        if(num == 0){ans = 0; break;}
        ans = mul_modp(ans, pow_modp(prev, num, INF), INF);
        prev = num; n++;
    }

    cout << ans << endl;

    return 0;
}