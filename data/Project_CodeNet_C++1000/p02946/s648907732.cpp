#include <bits/stdc++.h>

using namespace std;

#define ll long long




void solve() {

	
	int k, x;	
	cin >> k >> x;
	for(int i = max(-1000000, x - k + 1); i <= min(1000000, x + k - 1); i++) {
		cout << i << " ";
	}	
	




	
}

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	solve();

	return 0;
}
