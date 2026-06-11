#include <iostream>
#include <cstdio>
#include <iomanip>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <bitset>
#include <stack>
#include <utility>
#include <numeric>
#include <algorithm>
#include <functional>
#include <cctype>
#include <complex>
#include <string>
#include <sstream>
#include <cassert>
using namespace std;

//common
typedef long long ll;
// using i32=int;using i64=long long;using ll =i64;
// using uint=unsigned int;using ull=unsigned long long;
// template<typename T> using matrix=vector<vector<T> >;

#define BR "\n"
#define ALL(c) (c).begin(),(c).end()
#define REP(i,n) for(int i=0;i<(int)(n);++i)
#define EACH(it,o) for(auto it = (o).begin(); it != (o).end(); ++it)
#define IN(l,v,r) ((l)<=(v) && (v)<(r))

//config
//#undef NDEBUG
//#define INF 1<<30
//#define EPS 1e-8
//const ll MOD =100000007;

//debug
#ifdef NDEBUG
#define DUMP(x)
#define DUMPLN(x)
#define DEBUG(x)
#define DEBUGLN(x)
#define LINE()
#define LINELN()
#define CHECK(exp,act)
#define STOP(e)
#else
#define DUMP(x)  cerr << #x << " = " << (x)
#define DUMPLN(x)  DUMP(x) <<endl
#define DEBUG(x) DUMP(x) << LINE() << " " << __FILE__
#define DEBUGLN(x) DEBUG(x)<<endl
#define LINE()    cerr<< " (L" << __LINE__ << ")"
#define LINELN()    LINE()<<endl
#define CHECK(exp,act)  if(exp!=act){DUMPLN(exp);DEBUGLN(act);}
#define STOP(e)  CHECK(e,true);if(!(e)) exit(1);
#endif

template<class T> inline string toString(const vector<T>& x) {
	stringstream ss;
	REP(i,x.size()){
		if(i!=0)ss<<" ";
		ss<< x[i];
	}
	return ss.str();
}

template<class T> inline string toString(const vector<vector<T> >& map) {
	stringstream ss;
	REP(i,map.size()){
		if(i!=0)ss<<BR;
		ss<< toString(map[i]);
	}
	return ss.str();
}
template<class K,class V>  string toString(map<K,V>& x) {
	string res;stringstream ss;
	for(auto& p:x)ss<< p.first<<":" << p.second<<" ";
	return ss.str();
}

string BITtoString(int bit){
    stringstream ss;
    while(bit!=0){ss<<(bit%2);bit/=2;}
    string res=ss.str();reverse(ALL(res));
    return res;
}

template<typename T,typename V> inline T mod(T v,V MOD){
	return (v%MOD+MOD)%MOD;
}

ll INF=1LL<<58;
class Main{
public:
	void run(){
		while(true){
			int W,H;cin >> W >> H;if(W==0)break;
			vector<vector<int>> dp(H,vector<int>(W,0));
			int n;cin >>n;
			REP(i,n){
				int x,y;cin >> x >> y;x--;y--;
				dp[y][x]=-1;
			}
			dp[0][0]=1;
			REP(y,H)REP(x,W)if(dp[y][x]!=-1){
				if(y-1>=0 && dp[y-1][x]!=-1)dp[y][x]+=dp[y-1][x];
				if(x-1>=0 && dp[y][x-1]!=-1)dp[y][x]+=dp[y][x-1];
			}

			cout << dp[H-1][W-1]<<endl;
		}
	}
};
int main(){
  	Main().run();
  	return 0;
 }