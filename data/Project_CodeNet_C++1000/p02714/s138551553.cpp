//include
#include <vector>
#include <list>
#include <map>
#include <climits>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <queue>
using namespace std;
//------------------------------------------
//typedef
typedef long long ll;
typedef vector<int> VI;
typedef vector<bool> VB;
typedef vector<char> VC;
typedef vector<double> VD;
typedef vector<long long> VL;
typedef vector<VI> VVI;
typedef vector<VB> VVB;
typedef vector<string> VS;
typedef vector<VL> VVL;
typedef pair<int, int> PII;
typedef pair<ll, ll> Pll;
typedef pair<int, string> PIS;
typedef pair<string, int> PSI;
typedef pair<string, string> PSS;
//------------------------------------------
//comparison
#define C_MAX(a, b) ((a)>(b)?(a):(b))
#define C_MIN(a, b) ((a)<(b)?(a):(b))
#define C_ABS(a, b) ((a)<(b)?(b)-(a):(a)-(b))
//------------------------------------------
//container util
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define SZ(a) int((a).size())
#define EXIST(s, e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())
#define RSORT(c) sort((c).rbegin(),(c).rend())
#define REVERSE(c) reverse((c).begin(), (c).end())
#define SUMI(obj) accumulate((obj).begin(), (obj).end(), 0)
#define SUMD(obj) accumulate((obj).begin(), (obj).end(), 0.)
#define SUML(obj) accumulate((obj).begin(), (obj).end(), 0ll)
#define UB(obj, n) upper_bound((obj).begin(), (obj).end(), n)
#define LB(obj, n) lower_bound((obj).begin(), (obj).end(), n)
#define BS(v, n) binary_search(ALL(v), (n))
#define PB push_back
#define MP make_pair
//------------------------------------------
//repetition
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define RFOR(i, a, b) for(int i=(b)-1;i>=(a);--i)
#define REP(i, n)  FOR(i,0,n)
#define RREP(i, n) for(int i = n-1;i >= 0;i--)
#define FORll(i, a, b) for(ll i=ll(a);i<ll(b);++i)
#define RFORll(i, a, b) for(ll i=ll(b)-1;i>=ll(a);--i)
#define REPll(i, n) for(ll i=0;i<ll(n);++i)
#define RREPll(i, n) for(ll i=ll(n)-1;i>=0;--i)
#define FOREACH(x, v) for(auto &(x) : (v))
#define FORITER(x, v) for(auto (x) = (v).begin(); (x) != (v).end(); ++(x))
//------------------------------------------
//input output
#define GL(s) getline(cin, (s))
#define GET_MACRO(_1,_2,_3,NAME,...) NAME
#define IN(...) GET_MACRO(__VA_ARGS__, IN3, IN2, IN1)(__VA_ARGS__)
#define IN1(n) std::cin>>(n);
#define IN2(n,m) std::cin>>(n)>>(m);
#define IN3(n,m,l) std::cin>>(n)>>(m)>>(l);
#define OUT(d) std::cout<<(d);
#define OUT_L(d) std::cout<<(d)<<endl;
#define FOUT(n, d) std::cout<<std::fixed<<std::setprecision(n)<<(d);
#define EL() std::cout << "\n";
//------------------------------------------
//constant
#define MOD 1000000007
//------------------------------------------

//数値・文字列
inline int toInt(string s) {
    int v;
    istringstream sin(s);
    sin >> v;
    return v;
}
inline ll toLongLong(string s) {
    ll v;
    istringstream sin(s);
    sin >> v;
    return v;
}
template<class T>
inline string toString(T x) {
    ostringstream sout;
    sout << x;
    return sout.str();
}
inline VC toVC(string s) {
    VC data(s.begin(), s.end());
    return data;
}
//------------------------------------------

//other functions
//------------------------------------------
inline ll mypow(int k, int n){
    ll ans = 1;
    REP(i,n){
        ans *= k;
    }
    return ans;
}
//最大公約数
template<class T>
inline T GCD(const T x, const T y) {
    if (x < 0)return GCD(-x, y);
    if (y < 0)return GCD(x, -y);
    return (!y) ? x : GCD(y, x % y);
}

//最小公倍数
template<class T>
inline T LCM(const T x, const T y) {
    if (x < 0)return LCM(-x, y);
    if (y < 0)return LCM(x, -y);
    return x * (y / GCD(x, y));
}
//-----------------------------------------


//main code--------------------------------
void _main(){
    ll out = 0;
    int n;IN(n);
    string s;IN(s);
    VI r(n,0),g(n,0),b(n,0),rgb(n,0);
    RFOR(i,0,n){
        int rc=r[i],gc=g[i],bc=b[i];
        if(s[i]=='R') {rc++;rgb[i]=1;}
        if(s[i]=='G') {gc++;rgb[i]=10;}
        if(s[i]=='B') {bc++;rgb[i]=100;}
        if(i<1) break;
        r[i-1]=rc;
        g[i-1]=gc;
        b[i-1]=bc;
    }
    REP(j,n){
        FOR(i,j+1,n){
            if(rgb[j]==rgb[i]) continue;
            int s=rgb[j];
            s+=rgb[i];
            int k;
            if(s==110) k=r[i];
            if(s==101) k=g[i];
            if(s==11) k=b[i];
            if(i+i-j<n){
                s+=rgb[i+(i-j)];
                if(s==111) out--;
            }
            out+=k;
        }
    }
    OUT_L(out);
    return;
}
int main() {
    cout << fixed << setprecision(10);
    _main();
    return 0;
}