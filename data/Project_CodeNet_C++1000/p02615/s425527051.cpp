#include <bits/stdc++.h>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> A(N);
	for (int& a : A) cin >> a;
	sort(begin(A), end(A));
	reverse(begin(A), end(A));
	int64_t ans = 0;
	queue<int> Q;
	Q.push(A[0]);
	for (int i = 1; i < A.size(); ++i) {
		// cout << Q.front() << " " << A[i] << endl;
		ans += Q.front();
		Q.pop();
		Q.push(A[i]);
		Q.push(A[i]);
	}
	cout << ans << endl;
}