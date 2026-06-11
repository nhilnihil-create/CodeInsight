// In the name of God

#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int k;
	cin >> k;
	
	string s;
	cin >> s;

	cout << s.substr(0, min(k, (int)s.length()));

	if(s.length() > k) cout << "...";

	return 0;
}
