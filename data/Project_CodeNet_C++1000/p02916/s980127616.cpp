#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MOD = 1000000007;
const ll INF = 1LL<<60;
//int INF = numeric_limits<int>::max();

int main(int, char**) {
	int n; cin >> n;
	vector<int> A(n), B(n), C(n-1);
	for (int i=0; i<n; i++) cin >> A[i];
	for (int i=0; i<n; i++) cin >> B[i];
	for (int i=0; i<n-1; i++) cin >> C[i];
	int ret = 0;
	ret += B[A[0] - 1];
	int prev = A[0];
	for (int i=1; i<n; i++) {
		ret += B[A[i] - 1];
		if (A[i] == prev + 1) ret += C[prev-1];
		prev = A[i];
	}
	cout << ret << endl;
	return 0;
}