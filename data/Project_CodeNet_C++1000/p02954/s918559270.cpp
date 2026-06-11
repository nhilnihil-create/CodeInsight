#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <math.h>
#include <map>
#include <iomanip>
#include <queue>
#include <numeric>
#define repl(i, l, r) for (ll i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)

using namespace std;
using ll = long long;

int main() {

	string S;
	cin >> S;

	ll N = S.size();

	vector<ll> R(N, 0), L(N, 0);
	ll tmp = 0;

	rep(i, N - 1) {
		if (S[i] == 'R' && S[i + 1] == 'L') {
			R[i] = tmp + 1;
			tmp = 0;
		}
		else if (S[i] == 'R') {
			tmp++;
		}
	}
	for (ll i = N - 1; i > 0; i--) {
		if (S[i - 1] == 'R' && S[i] == 'L') {
			L[i] = tmp + 1;
			tmp = 0;
		}
		else if (S[i] == 'L') {
			tmp++;
		}
	}

	vector<ll> ans(N, 0);

	rep(i, N) {
		if (R[i] > 0) {
			ans[i] += (R[i] + 1) / 2;
			ans[i + 1] += R[i] / 2;
		}
		if (L[i] > 0) {
			ans[i] += (L[i] + 1) / 2;
			ans[i - 1] += L[i] / 2;
		}
	}

	rep(i, N) {
		cout << ans[i] << " ";
	}
	

	return 0;
}