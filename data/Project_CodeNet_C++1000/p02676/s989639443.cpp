#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)
#define MOD 998244353

using namespace std;
using ll = long long;

int main() {
	int k;
	string s;
	cin >> k >> s;
	if (k >= s.size()) cout << s;
	else {
		rep(i,k) cout << s[i];
		cout << "...";
	}
	cout << endl;
	return 0;
}
