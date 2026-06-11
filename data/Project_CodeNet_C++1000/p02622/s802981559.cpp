#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	string t,s;
	cin >> t >> s;
	int n = t.length();
	int ans = 0;
	for(int i=0; i<n; i++) {
		if(t[i]!=s[i]) ans++;
	}
	cout << ans;
	return 0;
}