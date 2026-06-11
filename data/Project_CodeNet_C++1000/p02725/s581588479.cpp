#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using LL = long long;

int main() {
	LL K, N;
	cin >> K >> N;
	vector<LL> A(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	sort(A.begin(), A.end());
	LL ans = 0;
	for (int i = 1; i < N; i++) {
		LL temp = A[i] - A[i - 1];
		ans = max(temp, ans);
	}
	LL t = A[0] - A[N - 1] + K;
	ans =  K -max(ans, t);
	cout << ans << endl;
	return 0;
}