#include<bits/stdc++.h>
using namespace std;
 
signed main() {
	string s;
	cin >> s;
 
	if (s.size() == 1) {
		cout << 1 << endl;
		return 0;
	}
	if (s.size() == 2) {
		if (s[0] == s[1]) cout << 1 << endl;
		else cout << 2 << endl;
		return 0;
	}
 
	int sz = s.size();
 
	s.push_back('A');
 
	int ans = 0;
	bool flag = true;
	for (int i = 0; i < s.size() - 1; i++) {
		if (i == sz - 2 && flag && s[i] == s[i + 1]) {
			ans++;
			break;
		}
		if (flag) {
			ans++;
			if (s[i + 1] == s[i]) flag = false;
		}
		else {
			ans++;
			i++;
			flag = true;
		}
		
	}
 
	
 
	cout << ans << endl;
	return 0;
}