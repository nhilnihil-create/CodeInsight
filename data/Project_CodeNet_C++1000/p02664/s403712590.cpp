#include<bits/stdc++.h>
using ll = long long;
using namespace std;
const ll INF = 1000000000000000000;
const ll mod = 1000000007;
//printf("%.10f\n", n);
signed main() {
	ll n; string s; cin >> s;
	for (int h = 0; h < s.size(); h++) {
		if (s[h] == '?') { s[h] = 'D'; }
	}
	cout << s << endl;
	cin >> n; return 0;
}