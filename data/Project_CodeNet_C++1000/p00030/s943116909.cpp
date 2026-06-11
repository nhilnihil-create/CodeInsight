#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES

#include "bits/stdc++.h"
#define REP(i,a,b) for(int i=a;i<b;++i)
#define rep(i,n) REP(i,0,n)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define ALL(a) begin(a),end(a)
#define ifnot(a) if(not (a))
#define dump(x)  cerr << #x << " = " << (x) << endl
using namespace std;

// #define int ll
#ifdef _MSC_VER
const bool test = true;
#else 
const bool test = false;
#endif

int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };
#define INF (1 << 28)
ull mod = (int)1e9 + 7;
//.....................
const int MAX = (int)2e5 + 5;

int n, s;

ll dfs(int v, int sum, int depth) {
	ll res = 0;
	if (depth == n) {
		if (sum == s) return 1;
		else return 0;
	}
	REP(i, v + 1, 10) {
		ll tmp = dfs(i, sum + i, depth + 1);
		res += tmp;
		if (false) {
			cout << "dfs(" << i << "," << sum + i << "," << depth + 1
				<< ") = " << tmp << endl;
		}
	}
	return res;
}

int main() {
	while (1) {
		cin >> n >> s;
		if (n == 0) break;
		// dump(dfs(2, 6, 3));
		cout << dfs(-1, 0, 0) << endl;
	}
	return 0;
}