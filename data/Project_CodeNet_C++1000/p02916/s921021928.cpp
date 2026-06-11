#include <bits/stdc++.h>

using namespace std;

#define ll long long




void solve() {

	
	int n;
	cin >> n;
	int a[n], b[n], c[n];
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		a[i]--;
	}
	for(int i = 0; i < n; i++) {
		cin >> b[i];
	}
	c[0] = 0;
	for(int i = 1; i < n; i++) {
		cin >> c[i];
	}
	ll total = b[a[0]];
	for(int i = 1; i < n; i++) {
		total += b[a[i]];
		if(a[i - 1] + 1 == a[i]) {
			total += c[a[i]];
		}
	}
	cout << total;	




	
}

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	solve();

	return 0;
}