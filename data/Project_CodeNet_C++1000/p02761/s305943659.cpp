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

	int n,m;
	cin >> n >> m;
	vector<int> vec(n, -1);
	bool flag = true;
	rep(i, m) {
		int s, c;
		cin >> s >> c;
		if (vec[s-1] == -1) vec[s-1] = c;
		else if (vec[s-1] != c) {
			flag = false;
			break;
		}
	}

	if (flag == false) {
		cout << -1;
	} else {
		if (vec[0] == 0 && n != 1) cout << -1;
		else {
			rep(i,n) {
				if (vec[i] != -1) cout << vec[i];
				else if (i==0 && n!=1) cout << 1;
				else if (i==0 && n==1) cout << 0;
				else cout << 0;
			}
		}
	}

}
//----------------------------------------------------------------------

int main(int argc, char* argv[]) {
	solve();
	return 0;
}
