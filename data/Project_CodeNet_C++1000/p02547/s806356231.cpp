#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <cmath>
#include <map>
#include <iomanip>
#include <unordered_map>
#include <stack>
#include <cstring>
#include <cctype>
#include <random>

using namespace std;
typedef long long  ll;
const ll INF = 1000000007;
const ll mod = 1000000007;
#define rep(i, n) for (int i = 0; i < (n); ++i)


int main() {
	ll N;
	cin >> N;
	vector<vector<ll>> d(N, vector<ll>(2));
	rep(i, N) {
		cin >> d[i][0] >> d[i][1];
	}
	for (int i = 2; i < N; i++) {
		bool aa = true;
		rep(j, 3) {
			if (d[i - j][0] != d[i - j][1]) {
				aa = false;
			}
		}
		if (aa) {
			cout << "Yes" << endl;
			return 0;
		}
	}
	cout << "No" << endl;
	return 0;
}