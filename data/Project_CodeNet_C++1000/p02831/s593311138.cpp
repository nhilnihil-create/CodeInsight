#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <cmath>
#include <stack>
#include <queue>
#include <functional>
#include <limits.h>
#include <set>
#include <map>
#include <tuple>
using namespace std;

#define ll long long
#define ull unsigned long long
#define rep(i,N) for (ll i=0;i<N;i++)
#define loop(i,N,M) for(ll i=N;i<M;i++)
#define MAX(v) *max_element(v.begin(),v.end())
#define MIN(v) *min_element(v.begin(),v.end())
#define SORTL2S(type,v) sort(v.begin(),v.end(),greater<type>())
#define SORTS2L(type,v) sort(v.begin(),v.end())
#define SORTMF(v,func) sort(v.begin(),v.end(),func)
#define MP(a,b) make_pair(a,b)

#if __has_include("debug.hpp")
#include "debug.hpp"
#else
template<typename T>
void debug(T& obj) {}
#endif

template<typename T>
T in(){
	T val;
	cin >> val;
	return val;
}

template<typename T>
vector<T> inv(ll num) {
	vector<T> val(num);
	rep(i,num) cin >> val[i];
	return val;
}

//最大公約数
ll GCD(ll x, ll y) {
	ll tmp;
	if (y > x) {
		tmp	= x;
		x = y;
		y = tmp;
	}
	while (x%y != 0) {
		tmp = y;
		y = x%y;
		x = tmp;
	}
	return y;
}

//最小公倍数
ll LCM(ll x, ll y) {
	return x*y / GCD(x, y);
}

//----------------------------------------------------------------------
void solve() {

	ll a,b;
	cin >> a>>b;
	cout << LCM(a,b);

}
//----------------------------------------------------------------------

int main(int argc, char* argv[]) {
	solve();
	return 0;
}
