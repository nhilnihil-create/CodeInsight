#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, k, c;
	cin >> n >> k >> c;
	string s;
	cin >> s;
	
	vector<int> L, R;
	int t = 1e9;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'o' && t >= c) {
			L.push_back(i);
			t = 0;
		}
		else t++;
		if (L.size() == k) break;
	}
	
	t = 1e9;
	for (int i = n - 1; i >= 0; i--) {
		if (s[i] == 'o' && t >= c) {
			R.push_back(i);
			t = 0;
		}
		else t++;
		if (R.size() == k) break;
	}
	
	reverse(R.begin(), R.end());
	for (int i = 0; i < k; i++) {
		if (L[i] == R[i]) cout << L[i] + 1 << '\n';
	}
	
	return 0;
}