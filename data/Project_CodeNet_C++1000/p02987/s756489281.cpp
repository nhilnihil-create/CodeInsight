#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	string s;
	cin >> s;
	set<char> ans;
	for (int i = 0; i < s.size(); i++) {
		ans.insert(s[i]);
	}
	if (ans.size() == 2) cout << "Yes" << "\n";
	else cout << "No" << "\n";
	return 0;
}
