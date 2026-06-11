#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);cin.tie(0);
	int n;
	cin >> n;
	map<int, int> mp, mp2;
	for(int i=0; i<n; i++) {
		int t;
		cin >> t;
		mp[t]++;
	}
	for(auto pr: mp) {
		mp2[pr.second]++;
	}
	vector<int> c(n+1);
	for(auto pr: mp2) {
		c[pr.first] = pr.second;
	}
	int mxn = n, cur = n;
	cout << n << '\n';
	for(int k=2; k<=mxn; k++) {
		while(n/k < cur) {
			n -= c[cur];
			c[cur-1] += c[cur];
			c[cur] = 0;
			cur--;
		}
		cout << cur << '\n';
	}
}