#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int x, n;
	cin >> x >> n;

	map<int, int> mp;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		mp[num] = 1;
	}
	
	int add = 0;
	while (1) {
		if (mp[x - add]) {
			if (mp[x + add])
				add++;
			else
				break;
		} else {
			add *= -1;
			break;
		}
	}
	cout << x + add << endl;

	return 0;
}