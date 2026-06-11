#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MOD = 1000000007;
const ll INF = 1LL<<60;
//int INF = numeric_limits<int>::max();

int main(int, char**) {
	ll a, b, v, w, t;
	cin >> a >> v >> b >> w >> t;
	if (v <= w) {
		cout << "NO" << endl;
		return 0;
	}
	if (abs(a - b) <= (v - w) * t) {
		cout << "YES" << endl;
		return 0;
	}
	cout << "NO" << endl;
	return 0;
}