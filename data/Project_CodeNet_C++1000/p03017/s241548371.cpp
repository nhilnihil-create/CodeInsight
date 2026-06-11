#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout << '>' << #x << ':' << x << endl;
#define ll long long

int main() {
	int n, a, b, c, d;
	cin >> n >> a >> b >> c >> d;
	string s;
	cin >> s;
	a--;
	b--;
	c--;
	d--;
	if (s[c] == '#' || s[d] == '#')
		return cout << "No", 0;
	if (c == d)
		return cout << "No", 0;
	if (d > c) {
		for (int i = a; i < d; i++) {
			if (s[i] == '#' && s[i + 1] == '#')
				return cout << "No", 0;
		}
		cout << "Yes\n";
	} else if (d < c) {
		for (int i = a; i < c; i++) {
			if (s[i] == '#' && s[i + 1] == '#')
				return cout << "No", 0;
		}
		for (int i = b-1; i < d; i++) {
			if (s[i] == '.' && s[i + 1] == '.' && s[i + 2] == '.') {
				return cout << "Yes", 0;
			}
		}
		cout << "No";
	}
}
