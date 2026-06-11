#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void solve(int n, vector<int>& arr) {
	unordered_map<int, vector<int>> mp;
	for (int i=0; i<n; i++) mp[arr[i]].push_back(i);
	if (mp[1].size() == 1) {
		cout << 1;
		return;
	}
	if (mp[1].size() > 1) {
		cout << 0;
		return;
	}
	int cnt = 0;
	for (auto a : arr) {
		if (mp[a].size() > 1) continue;
		cnt++;
		for (int i=2; i<=sqrt(a); i++) {
			if (a % i == 0 && (mp[i].size() > 0 || mp[a/i].size() > 0)) {
				cnt--;
				break;
			}
		}
	}
	cout << cnt;
	
}

int main() {
	int n; cin >> n;
	vector<int> arr(n);
	for (int i=0; i<n; i++) cin >> arr[i];
	solve(n, arr);
}	
