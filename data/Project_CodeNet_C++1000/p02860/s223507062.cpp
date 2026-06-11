#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	freopen("out.o", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	string s;
	cin >> s;
	if (n % 2 != 0) {
		cout << "No";
	}
	else {
		string t = s.substr(0, n / 2), v = s.substr(n / 2, n);
		if (t == v)cout << "Yes";
		else cout << "No";
	}
}