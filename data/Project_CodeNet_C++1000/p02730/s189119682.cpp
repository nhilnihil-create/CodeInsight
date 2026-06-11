#include<bits/stdc++.h>
using namespace std;

int main() {
	string s;
	cin >> s;
	int n = s.size();
	bool b = true;
	for (int i = 0; i < n / 2; i++) {
		if (s[i] != s[n-1-i]) b = false;
	}
	for (int i = 0; i < n / 2; i++) {
		if (s[i] != s[n / 2 - 1 - i]) b = false;
	}
	for (int i = n / 2; i < n; i++) {
		if (s[i] != s[n - 1 - i]) b = false;
	}
	if (b) cout << "Yes" << endl;
	else cout << "No" << endl;
}