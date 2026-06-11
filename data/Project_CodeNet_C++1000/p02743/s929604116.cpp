#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;

typedef int _loop_int;
#define REP(i,n) for(_loop_int i=0;i<(_loop_int)(n);++i)
#define FOR(i,a,b) for(_loop_int i=(_loop_int)(a);i<(_loop_int)(b);++i)
#define FORR(i,a,b) for(_loop_int i=(_loop_int)(b)-1;i>=(_loop_int)(a);--i)

#define VIN(v) for(auto&elem_: (v) )cin>>elem_
#define VOUT(v, sep) for(_loop_int idx=0; idx<(_loop_int)v.size(); idx++) {cout<<v[idx]; if(idx<(_loop_int)v.size()-1) cout<<sep;} cout<<endl
#define ALL(a) (a).begin(),(a).end()

#define DEBUG(x) cerr<<#x<<": "<<x<<endl
#define DEBUG2(x,y) cerr<<#x<<": "<<x<<" "<<#y<<": "<<y<<endl
#define DEBUG_VEC(v) cerr<<#v<<":";REP(debugidx,v.size())cerr<<" "<<v[debugidx];cerr<<endl
#define DEBUG_ARR(v,n) cerr<<#v<<":";REP(debugidx,n)cerr<<" "<<v[debugidx];cerr<<endl

const ll MOD = 1000000007ll;
const int IINF = numeric_limits<int>::max()/2-1;
const ll LINF = numeric_limits<ll>::max()/2-1;

template<class T> inline bool chmin(T& a, const T b) { if (a>b) { a=b; return true; } return false; }
template<class T> inline bool chmax(T& a, const T b) { if (a<b) { a=b; return true; } return false; }

#define dame { puts("-1"); return 0;}
#define yn {puts("Yes");}else{puts("No");}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    long double a,b,c;
    cin>>a>>b>>c;
    long double x = sqrt(a);
    long double y = sqrt(b);
    //long double z = sqrt(c);
    
    if(a+b + 2*(x*y) < c) yn;
    return 0;
}