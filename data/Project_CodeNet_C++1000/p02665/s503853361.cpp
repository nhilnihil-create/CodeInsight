#include "bits/stdc++.h"
//#include <intrin.h>  //AtCoder (gcc) 上ではこれがあると動かない。__popcnt用のincludeファイル。
using namespace std;

typedef long long ll;
typedef long double ld;


#define int long long
#define rep(i, n) for(long long i = 0; i < (n); i++)
#define sqrt(d) pow((long double) (d), 0.50)

const int INF = 2000000000; //2e9
const long long INF2 = 3000000000000000000; //3e18
const long double PI = acos(-1);

const int large_P = 1000000007; //1e9 + 7
//const int large_P = 1000000009; //1e9 + 9
//const int large_P = 998244353;





signed main() {
	int N; cin >> N;

	vector<int> leaf(N + 1);
	rep(i, N + 1) cin >> leaf.at(i);

	vector<int> vol(N + 1);
	bool able = true;

	for (int i = 0; i <= N; i++) {
		if (i == 0) {
			vol.at(i) = 1;
			if (leaf.at(i) > 0) {
				able = false;
				break;
			}
		}
		else {
			vol.at(i) = 2 * vol.at(i - 1);
			vol.at(i) -= leaf.at(i);

			if (vol.at(i) < 0 || (i != N && vol.at(i) == 0)) {
				able = false;
				break;
			}

			if (vol.at(i - 1) + leaf.at(i) > INF2 / 2) vol.at(i) = INF2;
		}
	}


	for (int i = N; i >= 0; i--) {
		if (i == N) {
			vol.at(i) = 0;
		}
		else {
			vol.at(i) = min(leaf.at(i + 1) + vol.at(i + 1), vol.at(i));
			if (vol.at(i) <= 0) {
				able = false;
				break;
			}
		}

	}


	int res = 0;
	for (int i = 0; i <= N; i++) {
		res += leaf.at(i) + vol.at(i);
	}


	if (able && N != 0) cout << res << endl;
	//if (able) cout << res << endl;
	else if (N == 0 && leaf.at(0) == 1) cout << "1" << endl;
	else cout << "-1" << endl;

	//rep(i, N + 1) {
		//cout << i << " " << vol.at(i) << endl;
	//}
}