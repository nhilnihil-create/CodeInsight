#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MOD = 1000000007;
const ll INF = 1LL<<60;
//int INF = numeric_limits<int>::max();

int main(int, char**) {
	int n, k; cin >> n >> k;
	int upr = (n - 2) * (n - 1) / 2;
	if (k > upr) {
		cout << -1 << endl;
		return 0;
	}
	int m = n - 1 + (upr - k);
	cout << m << endl;
	for (int i=0; i< n - 1; i++) {
		cout << 1 << " " << i+2 << endl;
	}
	if (upr - k == 0) return 0;
	int cnt = 0;
	for (int j=2; j < n; j++) {
		for (int i=j+1; i < n+1; i++) {
			cout << j << " " << i << endl;
			cnt++;
			if (cnt==(upr - k)) break;
		}
		if (cnt==(upr - k)) break;
	}
	return 0;
}