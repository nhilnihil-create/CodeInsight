#include<iostream>
#include<vector>
using namespace std;

const int MAX = 1000005;

int main() {

	int N;
	cin >> N;

	vector<int> cnt(MAX);
	vector<int> A(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		int x = 0;
		if (cnt[A[i]] != 0) {
			cnt[A[i]]++;
			continue;
		}
		while (x + A[i] < MAX) {
			x += A[i];
			cnt[x]++;
		}
	}

	int ans = 0;
	for (int i = 0; i < N; i++) {
		if (cnt[A[i]] == 1) {
			ans++;
		}
	}

	cout << ans << endl;

	return 0;
}