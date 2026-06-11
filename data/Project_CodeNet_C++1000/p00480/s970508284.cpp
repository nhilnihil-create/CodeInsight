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
//using i32=int;using i64=long long;
typedef long long ll;
// using uint=unsigned int;using ull=unsigned long long;
// template<typename T> using matrix=vector<vector<T> >;

#define BR "\n"
#define ALL(c) (c).begin(),(c).end()
#define REP(i,n) for(int i=0;i<(int)(n);++i)
#define EACH(it,o) for(auto it = (o).begin(); it != (o).end(); ++it)
#define IN(l,v,r) ((l)<=(v) && (v)<(r))

//config
#define MODE_DEBUG
//#define INF 1<<30
//#define EPS 1e-8
//const ll MOD =100000007;

//debug
#ifdef MODE_DEBUG
#define DUMP(x)  cerr << #x << " = " << (x)
#define DUMPLN(x)  DUMP(x) <<endl
#define DEBUG(x) DUMP(x) << LINE() << " " << __FILE__
#define DEBUGLN(x) DEBUG(x)<<endl
#define LINE()    cerr<< " (L" << __LINE__ << ")"
#define LINELN()    LINE()<<endl
#define CHECK(exp,act)  if(exp!=act){DUMPLN(exp);DEBUGLN(act);}
#define STOP(e)  CHECK(e,true);if(!(e)) exit(1);
#else
#define DUMP(x)
#define DUMPLN(x)
#define DEBUG(x)
#define DEBUGLN(x)
#define LINE()
#define LINELN()
#define CHECK(exp,act)
#define STOP(e)
#endif

template<class T> inline string toString(const vector<T>& x) {
	stringstream ss;
	REP(i,x.size()){
		if(i!=0)ss<<" ";
		ss<< x[i];
	}
	return ss.str();
}

template<class T> inline string toString(const vector<vector<T>>& map) {
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

//ind -> V から V->ind (注:単射)
template<typename T>
map<T,int> rev(const vector<T>& xs){
	map<T,int> rev;
	REP(i,(int)xs.size())rev.insert(make_pair(xs[i],i));
	return rev;
}

template<typename T,typename V> inline T mod(T v,V MOD){
	return (v%MOD+MOD)%MOD;
}

int main(){
	int n;cin >>n;
	vector<int> as(n);
	REP(i,n)cin >> as[i];
	vector<ll> dp(20+1);
	vector<ll> tmp(20+1);

	dp[as[0]]=1;
	for(int i=1;i<n-1;i++){
		for(int pv=0;pv<=20;pv++){
			int p=pv+as[i];
			if(IN(0,p,20+1))tmp[p]+=dp[pv];
			int m=pv-as[i];
			if(IN(0,m,20+1))tmp[m]+=dp[pv];
		}
		dp=tmp;
		fill(ALL(tmp),0);
		// DUMP(toString(dp));
		// DUMP(toString(tmp));
	}
	cout<<dp[as[n-1]]<<endl;

	return 0;
}