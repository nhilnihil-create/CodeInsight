#define _GLIBCXX_DEBUG
#include "bits/stdc++.h"
//#include <intrin.h>  //AtCoder (gcc) 上ではこれがあると動かない。__popcnt用のincludeファイル。
using namespace std;

typedef long long ll;
typedef long double ld;


#define int long long
#define rep(i, n) for(long long i = 0; i < (n); i++)
#define sqrt(d) pow((long double) (d), 0.50)

const int INF = 2000000000; //2e9
const int large_P = 1000000007; //1e9 + 7


signed main() {
	int N, M;
	cin >> N >> M;

	if (N % 2 == 1) {
		//cout << "hacked" << endl;
	}
	else {
		//cout << "hacked" << endl;
	}

	if (M % 2 == 1) {
		//cout << "hacked" << endl;
	}
	else {
		//cout << "hacked" << endl;
	}


	if (N % 2 == 1) {
		rep(i, M) {
			cout << i + 1 << " " << N - (i + 1) << endl;
		}
	}
	else {
		if (M % 2 == 1) {
			rep(i, M / 2) cout << i + 1 << " " << M - i << endl;
			rep(i, M / 2 + 1) cout << M + i + 1 << " " << 2 * M + 1 - i << endl;
		}
		else {
			rep(i, M / 2) cout << i + 1 << " " << M + 1 - i << endl;
			rep(i, M / 2) cout << M + i + 2 << " " << 2 * M + 1 - i << endl;
		}
	}


	


}