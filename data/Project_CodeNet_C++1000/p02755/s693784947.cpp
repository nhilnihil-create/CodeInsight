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

//----------------------------------------------------------------------
void solve() {

	int A,B;
	cin >> A >> B;

	rep(i,2000) {
		int _a = floor((double)i*0.08);
		int _b = floor((double)i*0.1);

		if (_a==A && _b==B) {
			cout << i;
			break;
		}

		if (i==1999) {
			cout << -1;
		}
	}

}
//----------------------------------------------------------------------

int main(int argc, char* argv[]) {
	solve();
	return 0;
}
