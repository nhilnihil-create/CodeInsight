#include<bits/stdc++.h>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> H(N);
	for (int i = 0; i < N; ++i) cin >> H[i];
	H.push_back(2000000000);
	int ans = 0;
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		if (H[i + 1] <= H[i]) cnt++;
		else {
			ans = max(ans, cnt);
			cnt = 0;
		}
	}
	cout << ans << endl;
	return 0;
}