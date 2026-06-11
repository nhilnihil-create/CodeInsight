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
typedef long long LL;
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
typedef pair<LL, LL> PLL;
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
#define SUML(obj) accumulate((obj).begin(), (obj).end(), 0LL)
#define UB(obj, n) upper_bound((obj).begin(), (obj).end(), n)
#define LB(obj, n) lower_bound((obj).begin(), (obj).end(), n)
#define BS(v, n) binary_search(ALL(v), (n))
#define PB push_back
#define MP make_pair
//------------------------------------------
//repetition
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define RFOR(i, a, b) for(int i=(b)-1;i>=(a);--i)å
#define REP(i, n)  FOR(i,0,n)
#define RREP(i, n) for(int i = n-1;i >= 0;i--)
#define FORLL(i, a, b) for(LL i=LL(a);i<LL(b);++i)
#define RFORLL(i, a, b) for(LL i=LL(b)-1;i>=LL(a);--i)
#define REPLL(i, n) for(LL i=0;i<LL(n);++i)
#define RREPLL(i, n) for(LL i=LL(n)-1;i>=0;--i)
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
inline LL toLongLong(string s) {
    LL v;
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

//ezaki's functions
inline LL mypow(int k, int n){
    LL ans = 1;
    REP(i,n){
        ans *= k;
    }
    return ans;
}
//-----------------------------------------

void _main(){
    LL x,k,d; IN(x,k,d);
    x = abs(x);   
    LL out;
    LL xside,q,over;
    xside=x%d; q = x/d;
    over =d-xside;
    if(q>=k) out = x-k*d;
    else {
        if((k-q)%2==0) out = xside;
        else out = over;
    } 
    OUT_L(out);
    return;
}
int main() {
    cout << fixed << setprecision(10);
    _main();
    return 0;
}