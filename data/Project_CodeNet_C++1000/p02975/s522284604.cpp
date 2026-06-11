#define _USE_NATH_DEFINES
#include <cstdio>
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <complex>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <bitset>
#include <numeric>
#include <limits>
#include <climits>
#include <cfloat>
#include <functional>
#include <iterator>
#include <random>
#include <tuple>


using namespace std;
#define REP(i,m,n) for(int i=(int)m ; i < (int) n ; ++i )
#define rep(i,n) REP(i,0,n)
using ll = long long;
#define EPS 1e-9
const int INF = 1050000000;
const long long LINF = 1LL << 60;
const ll MOD = 1e9 + 7;
const int MINF = -1050000000;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }


int main() {
	
	int n;
	deque<ll> a;

	cin >> n;
	a.resize(n);
	rep(i, n) cin >> a[i];
	
	/*
	ll begin = a[0], end = a[n-1];
	a.push_front(end);
	a.push_back(begin);
	bool ok = true;
	
	for (int i = 1; i < n+1; ++i) {
		ll self = a[i];
		ll l = a[i-1];
		ll r = a[i + 1];
		ll target = l ^ r;
		if (self != target) ok = false;
	}
	*/
	ll target = a[0];
	for(int i = 1; i < n; ++i) {
		target = target ^ a[i];
	}
	if (!target) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}
