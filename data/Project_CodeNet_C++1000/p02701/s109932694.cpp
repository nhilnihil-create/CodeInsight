#include <bits/stdc++.h>
#define rep(i,n) for(ll i = 0; i < (ll)(n); ++i)
#define MOD 1000000007

using namespace std;
using ll = long long;

int main() {
	int n;
	string s;
	list<string> str;
	cin >> n;
	rep (i,n) {
		cin >> s;
		str.push_back(s);
	}
	str.sort();;
	str.unique();
	int ans;
	ans = str.size();
	cout << ans << endl;
	return 0;
}
