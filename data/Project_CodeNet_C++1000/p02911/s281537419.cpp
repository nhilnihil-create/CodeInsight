#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MOD = 1000000007;
const ll INF = 1LL<<60;
//int INF = numeric_limits<int>::max();

int main(int, char**) {
	int n, k, q; cin >> n >> k >> q;
	vector<int> A(n, k - q);
	for (int i=0; i<q; i++) {
		int j; cin >> j; j--;
		A[j] += 1;
	}
	string ret;
	for (int i=0; i<n; i++) {
		if (A[i] <= 0) ret = "No";
		else ret = "Yes";
		cout << ret << endl;
	}
	return 0;
}