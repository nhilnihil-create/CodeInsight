#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> A(n);
	for (int& a : A)
		cin >> a;
	sort(A.begin(), A.end(), greater<int>());
	long long res = A[0];
	for (int i = 0; i < n - 2; ++i)
		res += A[i/2+1];
	cout << res << '\n';

	return 0;
}