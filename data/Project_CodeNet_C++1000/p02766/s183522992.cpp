#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MOD = 1000000007;
const ll INF = 1LL<<60;
//int INF = numeric_limits<int>::max();

int main(int, char**) {
	int ret = 1;
	int n, k; cin >> n >> k;
	int c = 1;
	while(true) {
		if (n >= c * k) {
			ret++;
			c *= k;
		} else break;
	}
	cout << ret << endl;
	return 0;
}