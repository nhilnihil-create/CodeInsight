#include <bits/stdc++.h>

using namespace std;

#define ll long long




void solve() {

	int n;
	string s;
	cin >> n >> s;
	int cnt = 1;
	for(int i = 1; i < n; i++) {
		if(s[i] != s[i - 1]) {
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