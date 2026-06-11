#include <bits/stdc++.h>

using namespace std;

#define ll long long




void solve() {

	
	int a, b;
	cin >> a >> b;
	int ans = a + b;
	if(ans & 1) {
		cout << "IMPOSSIBLE";
	}
	else {
		cout << ans / 2;
	}
	




	
}

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	solve();

	return 0;
}