#include<iostream>
#include<vector>
using namespace std;
int main() {

	int N;
	cin >> N;
	vector<int> cnt(N + 1);

	for (int i = 1; i < N + 1; i++) {
		for (int j = i; j < N + 1; j += i) {
			cnt[j]++;
		}
	}

	long long ans = 0;
	for (int i = 1; i < N + 1; i++) {
		ans += (long long)i * cnt[i];
	}

	cout << ans << endl;

	return 0;
}