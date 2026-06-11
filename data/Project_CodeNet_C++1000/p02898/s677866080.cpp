#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MOD = 1000000007;
const ll INF = 1LL<<60;
//int INF = numeric_limits<int>::max();

int main(int, char**) {
	int n, k; cin >> n >> k;
	int ret = 0;
	for (int i=0; i<n; i++) {
		int h; cin >> h;
		if (h >= k) ret++;
	}
	cout << ret << endl;
	return 0;
}