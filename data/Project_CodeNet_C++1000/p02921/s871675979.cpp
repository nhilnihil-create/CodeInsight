#include <bits/stdc++.h>

using namespace std;

#define ll long long




void solve() {

	string a, b;
	cin >> a >> b;
	int cnt = 0;
	for(int i = 0; i < a.length(); i++) {
		if(a[i] == b[i]) {
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