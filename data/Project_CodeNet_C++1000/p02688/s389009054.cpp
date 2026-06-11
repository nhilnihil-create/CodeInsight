#include<iostream>
#include<vector>
using namespace std;
int main() {
	int n, k; cin >> n >> k;
	vector<bool> sunuke(n, true);
	for (int i = 0; i < k; i++) {
		int okashi; cin >> okashi;

		for (int j = 0; j < okashi; j++) {
			int x; cin >> x;
			sunuke.at(x - 1) = false;
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (sunuke.at(i)) {
			ans++;
		}
	}
	cout << ans << endl;
}