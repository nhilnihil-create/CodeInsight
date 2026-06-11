#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {

	int N;
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; i++) cin >> A[i];

	sort(A.rbegin(), A.rend());

	long long ans = A[0];
	for (int i = 1; i <= (N - 2) / 2; i++) ans += (long long)A[i] * 2;
	if (N % 2 == 1) ans += A[(N - 2) / 2 + 1];

	cout << ans << endl;

	return 0;
}