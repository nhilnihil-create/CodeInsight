#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	int l = 0, r = n-1;
	int cnt = 0;
	while (l < r) {
		while (l < n) {
			if (s[l] == 'W') break;
			else l++;
		}
		while (r >= 0) {
			if (s[r] == 'R') break;
			else r--;
		}
		if (r > l) {
			cnt+=1;
			s[r] = 'W';
			s[l] = 'R';
		}
	}
	cout << cnt;
}
