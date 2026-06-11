#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string s;
	cin >> s;
	if (s[1] == 'B') s[1] = 'R'; else s[1] = 'B';
	cout << s;
	return 0;
}