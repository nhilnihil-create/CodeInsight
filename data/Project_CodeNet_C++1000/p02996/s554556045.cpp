#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int N;
	cin >> N;
	vector<pair<int, int> > W(N);
	for (int i = 0; i < N; ++i) {
		cin >> W[i].second >> W[i].first;
	}
	sort(W.begin(), W.end());
	long long sum = 0;
	bool ok = true;
	for (int i = 0; i < N; ++i) {
		sum += W[i].second;
		if (sum > W[i].first) {
			ok = false;
		}
	}
	cout << (ok ? "Yes" : "No") << endl;
	return 0;
}