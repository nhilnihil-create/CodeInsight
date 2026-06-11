#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int n; cin >> n;
	vector<int>x(n),l(n);
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> l[i];
	}
	vector<pair<int, int>>sg(n);
	for (int i = 0; i < n; i++) {
		sg[i] = { x[i] + l[i],x[i] - l[i] };
	}
	sort(sg.begin(), sg.end());

	int ans = 0, now = -1e9;
	for (int i = 0; i < n; i++) {
		if (now <= sg[i].second) {
			ans++; now = sg[i].first;			
		}
	}
	cout << ans << endl;

	return 0;
}