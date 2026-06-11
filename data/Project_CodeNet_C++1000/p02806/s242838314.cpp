#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;
	vector<string> song(n);
	vector<int> t(n);
	for(int i = 0; i < n; i++) {
		cin >> song[i] >> t[i];
	}
	
	string s;
	cin >> s;
	int ans = 0;
	bool ok = false;
	for(int i = 0; i < n; i++) {
		if(song[i] == s) {
			ok = true;
		} else if(ok) {
			ans += t[i];
		}
	}
	cout << ans << endl;
}
