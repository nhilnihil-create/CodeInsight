#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int MAX = 105;

int main() {

	int X, N;
	cin >> X >> N;
	if (N == 0) {
		cout << X << endl;
		return 0;
	}

	vector<int> cnt(MAX);
	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		cnt[x]++;
	}

	int ans;
	int y = 200;
	for (int i = 0; i < MAX; i++) {
		if (cnt[i] == 0) {
			if (abs(X - i) < y) {
				y = abs(X - i);
				ans = i;
			}
		}
	}

	cout << ans << endl;

	return 0;
}