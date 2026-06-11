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

	ll n;
	cin >> n;
	string p="",q="";
	vector<int> vec(n);
	rep(i,n) {
		int t;
		cin >> t;
		p += to_string(t);
		vec[i] = i+1;
	}
	rep(i,n) {
		int t;
		cin >> t;
		q += to_string(t);
	}

	debug(p);
	debug(q);

	map<string, ll> m;
	ll cnt = 0;
	do {
		string s="";
		rep(i,n) s+=to_string(vec[i]);
		m[s] = cnt;
		cnt++;
	}while(next_permutation(vec.begin(),vec.end()));

	cout << abs(m[p]-m[q]);



}
//----------------------------------------------------------------------

int main(int argc, char* argv[]) {
	solve();
	return 0;
}
