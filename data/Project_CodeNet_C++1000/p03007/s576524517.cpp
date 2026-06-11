
// C - Successive Subtraction

#include <bits/stdc++.h>
//#include <atcoder/all>
using namespace std;
//using namespace atcoder;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1000000007;
// using mint = modint1000000007;
// const ll MOD = 998244353;
// using mint = modint998244353;

int main() {
	int N;
	cin >> N;

	priority_queue<ll, vector<ll>, greater<ll>> positive;
	priority_queue<ll> negative;
	stack<ll> zero;

	for (int i=0; i<N; i++) {
		ll A;
		cin >> A;

		if (A > 0) positive.push(A);
		else if (A < 0) negative.push(A);
		else zero.push(A);
	}

	vector<pair<ll, ll>> ansVec;
	ll x, y;

	while(positive.size() + negative.size() + zero.size() > 2) {
		if (negative.size() == 0 && zero.size() == 0) {
			x = positive.top();
			positive.pop();
			y = positive.top();
			positive.pop();
		} else if (positive.size() == 0 && zero.size() == 0) {
			x = negative.top();
			negative.pop();
			y = negative.top();
			negative.pop();
		} else if (negative.size() == 0 && zero.size() > 0) {
			x = zero.top();
			zero.pop();
			y = positive.top();
			positive.pop();
		} else if (positive.size() == 0 && zero.size() > 0) {
			x = zero.top();
			zero.pop();
			y = negative.top();
			negative.pop();
		} else if (positive.size() > 1) {
			x = negative.top();
			negative.pop();
			y = positive.top();
			positive.pop();
		} else {
			x = positive.top();
			positive.pop();
			y = negative.top();
			negative.pop();
		}

		ansVec.push_back(make_pair(x, y));

		if (x - y > 0) positive.push(x - y);
		else if (x - y < 0) negative.push(x - y);
		else zero.push(0);
	}

	if (positive.size() == 2) {
		y = positive.top();
		x = positive.top();
	} else if (negative.size() == 2) {
		x = negative.top();
		y = negative.top();
	} else if (zero.size() == 2) {
		x = 0;
		y = 0;
	} else if (positive.size() == 1 && negative.size() == 1) {
		x = positive.top();
		y = negative.top();
	} else if (positive.size() == 1 && zero.size() == 1) {
		x = positive.top();
		y = 0;
	} else {
		x = 0;
		y = negative.top();
	}

	ansVec.push_back(make_pair(x, y));

	cout << x - y << endl;

	for (auto ans : ansVec) {
		cout << ans.first << " " << ans.second << endl;
	}

	return 0;
}