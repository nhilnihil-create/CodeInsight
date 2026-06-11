#include "bits/stdc++.h"
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int>A(N);
	for (int n = 0;n<N;++n) {
		cin >> A[n];
	}
	int num = 1;
	int ans = 0;
	for (int n = 0; n < N; ++n) {
		if (num == A[n]) {
			num++;
		}
		else {
			ans++;
		}
	}
	if (1 == num) {
		cout << -1<<endl;
	}
	else {
		cout << ans <<endl;
	}
	return 0;
}