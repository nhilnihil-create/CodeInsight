#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n,k;
	cin>>n>>k;
	vector<int> A(n);
	for (int& e : A) cin >> e;
		sort(A.begin(), A.end());
	int ans = 0;
	for (int i = 0; i < k; ++i) ans += A[i];
	cout << ans << endl;
}