#include "bits/stdc++.h"
//#include <intrin.h>  //AtCoder (gcc) 上ではこれがあると動かない。__popcnt用のincludeファイル。
using namespace std;

typedef long long ll;
typedef long double ld;


#define int long long
#define rep(i, n) for(long long i = 0; i < (n); i++)
#define sqrt(d) pow((long double) (d), 0.50)

const int INF = 2000000000; //2e9
const long long INF2 = 1000000000000000000; //1e18
const long double PI = acos(-1);

const int large_P = 1000000007; //1e9 + 7
//const int large_P = 1000000009; //1e9 + 9
//const int large_P = 998244353;




int dfs2(const vector<int>& parent, const vector<int>& pos, vector<int>& res, vector<bool>& seen, int v) {
	seen.at(v) = true;
	//cout << v << endl;

	if (parent.at(v) == v) {
		res.at(v) = pos.at(v);
		return pos.at(v);
	}

	if (seen.at(parent.at(v))) {
		res.at(v) = res.at(parent.at(v));
		return res.at(v);
	}

	
	return res.at(v) = dfs2(parent, pos, res, seen, parent.at(v));
}




signed main() {
	int N; cin >> N;
	long double res = 0.50;

	if (N % 2 == 1) {
		int tempo = N / 2 + 1;
		res = (long double)tempo / (long double)N;
	}

	printf("%.12Lf\n", (long double)res);

}