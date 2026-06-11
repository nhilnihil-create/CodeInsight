#include <bits/stdc++.h>
#include <iostream>

#define ll long long

using namespace std;

int main() {
	int n; cin >> n;
	ll k; cin >> k;
	vector<int> a(n+1);
	for (int i=0; i<n; i++) cin >> a[i+1];
	if (k > n) {
		vector<int> visit(n+1, -1);
		int cur = 1;
		visit[1] = 0;
		int cycle = n;
		for (int i=1; i<=n+1; i++) {
			cur = a[cur];
			if (visit[cur] != -1) {
				cycle = i-visit[cur];
				break;
			}
			visit[cur] = i;
		}
		k = (k-n) % cycle + n;
	}
	int cur = 1;
	while (k--) {
		cur = a[cur];
	}
	cout << cur;
}
