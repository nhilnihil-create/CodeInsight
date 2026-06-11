#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MOD = 1000000007;
const ll INF = 1LL<<60;
//int INF = numeric_limits<int>::max();

int main(int, char**) {
	int n; cin >> n;
	int ret = 0;
	int prev; cin >> prev;
	ret += prev;
	for (int i=1; i<n-1; i++) {
		int b; cin >> b;
		ret += min(prev, b);
		prev = b;
	}
	cout << ret + prev << endl;
	return 0;
}