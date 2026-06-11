#include "bits/stdc++.h"
using namespace std;

#define ll long long
#define rep(i,n) for(int i = 0;i < (n); i++)
#define mod 1000000007

int main() {
	string s;
	cin >> s;
	int ans = 0;
	rep(i, s.length() / 2) {
		if (s[i] != s[s.length() - i - 1])ans++;
	}
	cout << ans << endl;
	return 0;
}