#include <bits/stdc++.h>

using namespace std;

#define ll long long




void solve() {

	int n, k;
	cin >> n >> k;
	int cnt= 0;
	while(n--) {
		int x;
		cin >> x;
		if(x >= k) {
			cnt++;
		}
	}
	cout << cnt;


	




	
}

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	solve();

	return 0;
}
