#include <bits/stdc++.h>

using namespace std;

#define ll long long




void solve() {

	int n, k, q;
	cin >> n >> k >> q;
	ll arr[n];
	ll mx = 0;
	fill(arr, arr + n, k - q);
	while(q--) {
		int x;
		cin >> x;
		x--;
		arr[x]++;
	}
	for(int i = 0; i < n; i++) {
		if(arr[i] > 0) {
			cout << "Yes\n";
		}
		else {
			cout << "No\n";
		}

	}
	
	




	
}

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	solve();

	return 0;
}	