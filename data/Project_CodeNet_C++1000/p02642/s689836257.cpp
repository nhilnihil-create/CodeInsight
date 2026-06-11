#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	map<int, int> mp;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		mp[arr[i]]++;
	}
	sort(arr.begin(), arr.end());
	int resp = 0;
	for (int i = 0; i < n; i++) {
		int val = arr[i];
		for (int j = val * 2; j <= arr[n - 1]; j += val) {
			mp[j]++;
		}
		if (mp[val] == 1)
			resp++;
	}
	cout << resp << endl;

	return 0;
}