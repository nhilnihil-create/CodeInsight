#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int n, k;
	string s;
	cin >> n >> k;
	cin >> s;
	char x = s.at(0);
	int st = 1;
	int en= 0;
	for (int i = 0; i < k; i++) {
		en = s.length();
		for (int j = st-1; j < s.length(); j++) {
			if (s.at(j) == x)continue;
			else {
				st = j;
				for (int k = j; k < s.length(); k++) {
					if (s.at(st) != s.at(k)) {
						en = k;
						break;
					}
				}
				break;
			}
		}
		for (int j = st; j < en; j++)s.at(j) = x;
		st = en - 1;
	}
	ll ans = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s.at(i) == 'L') {
			if (i == 0)continue;
			else {
				if (s.at(i - 1) == 'L')ans++;
			}
		}
		else {
			if (i == s.length() - 1)continue;
			else {
				if (s.at(i + 1) == 'R')ans++;
			}
		}
	}
	//cout << s << endl;
	cout << ans << endl;
}