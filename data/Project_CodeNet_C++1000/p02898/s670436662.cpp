#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, K;
vector<int> H;

void input_init(void) {
	cin >> N >> K;
	H.resize(N);
	for (int i = 0; i < N; ++i)
		cin >> H[i];
}

int solve(void) {
	sort(H.begin(), H.end());
	vector<int>::iterator itr;
	itr = lower_bound(H.begin(), H.end(), K);
	int idx = (int)distance(H.begin(), itr);
	return N - idx;
}

int main(void) {
	input_init();
	int ans = solve();
	cout << ans << '\n';
	return 0;
}
