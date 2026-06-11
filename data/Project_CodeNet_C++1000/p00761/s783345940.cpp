#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(co) begin(co), end(co)

int main() {
	int n, l;
while (cin >> n >> l && n && l) {
	map<int, int> mp;		
	rep(i, 100) {
		mp[n] = i;
		string s = to_string(n);
		rep(i, l)if (s.size() < l) s += "0";
		string mi = s, ma = s;
		sort(all(mi));
		sort(all(ma), greater<int>());
		n = atoi(ma.c_str()) - atoi(mi.c_str());
		if (mp.count(n)) {
			cout << mp[n] << " " << n << " " << i + 1 - mp[n] << endl;
			break;
		}
	}
}
}