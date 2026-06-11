// ABC162D.cpp
//#include "pch.h"
#include <iostream>
#include <string>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
int main()
{
	int n;
	cin >> n;
	string s;
	cin >> s;
	int k=0;
	ll r_ans = 0;
	for (int j = 1; j < n - 1; j++) {
		rep(i, j) {
			k = 2 * j - i;
			if (k < n) {
				if (s[i] == s[j])continue;
				if (s[i] == s[k])continue;
				if (s[j] == s[k])continue;
				r_ans++;
			}
		}
	}
	int r=0,g=0,b=0;
	rep(i, s.size()) {
		if (s[i] == 'R') r++;
		if (s[i] == 'G') g++;
		if (s[i] == 'B') b++;
	}
	ll ans = r * g*b - r_ans;
	cout << ans << endl;
}
