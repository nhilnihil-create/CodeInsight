#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int n;
	cin >> n;
	vector<vector<int>>ba(n, vector<int>(2));
	for (int i = 0; i < n; i++)cin >> ba.at(i).at(1) >> ba.at(i).at(0);
	sort(ba.begin(), ba.end());
	ll t = 0;
	for (int i = 0; i < n; i++) {
		t += ba.at(i).at(1);
		if (t > ba.at(i).at(0)) {
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
}