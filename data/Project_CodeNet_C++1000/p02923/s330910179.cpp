#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MOD = 1000000007;
const ll INF = 1LL<<60;
//int INF = numeric_limits<int>::max();

int main(int, char**) {
	int n; cin >> n;
	int ret = 0;
	int step = 0;
	int ph; cin >> ph;
	for (int i=0; i<n-1; i++) {
		int h; cin >> h;
		if (h <= ph) {
			step++;
		} else {
			ret = max(ret, step);
			step = 0;
		}
		ph = h;
	}
	ret = max(ret, step);
	cout << ret << endl;
	return 0;
}