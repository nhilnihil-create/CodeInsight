#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MOD = 1000000007;
const ll INF = 1LL<<60;
//int INF = numeric_limits<int>::max();

int main(int, char**) {
	int n, l; cin >> n >> l;
	int ret = 0;
	int eat = 1000000;
	for (int i=0; i<n; i++) {
		ret += (l + i);
		if (abs(l+i) < abs(eat)) eat = l+i;
	}
	cout << ret - eat << endl;
	return 0;
}