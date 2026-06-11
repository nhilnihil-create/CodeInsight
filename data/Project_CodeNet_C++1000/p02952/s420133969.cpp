#include <bits/stdc++.h>

using namespace std;

#define ll long long




void solve() {

	int n;
	cin >> n;
	ll cnt = 0;
	for(int i = 1; i <= n; i++) {
		string s= to_string(i);
		if(s.length() & 1 )
			cnt++;
	}
	cout << cnt;
	




	
}

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	solve();

	return 0;
}