#include <bits/stdc++.h>

using namespace std;

#define ll long long




void solve() {

	int n;
	cin >> n;
	int a[n + 1], b[n + 1];
	for(int i = 0; i < n + 1; i++) {
		cin >> a[i];
	}
	for(int i = 0; i < n; i++) {
		cin >> b[i];
	}
	b[n] = 0;
	ll total = 0;
	//a = monsters;
	//b = heroes
	for(int i = 0; i < n + 1; i++) { 
		int mn = min(a[i], b[i]);
		a[i] -= mn;
		b[i] -= mn;
		total += mn;
		if(i + 1 == n + 1) {
			break;
		}
		mn = min(a[i + 1], b[i]);
		a[i + 1] -= mn; 
		b[i] -= mn;
		total += mn;
	}
	cout << total << "\n";

	

	
}

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	solve();

	return 0;
}