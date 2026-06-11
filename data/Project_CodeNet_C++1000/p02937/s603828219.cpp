#include <bits/stdc++.h>
using namespace std;


int main() {
	string s, t;
	cin >> s >> t;
	map<char, int> mp;
	for (int i = 0; i < (int) s.length(); i++) {
		mp[s[i]]++;
	}
	bool ok = true;
	for (int i = 0; i < (int)t.length(); i++) {
		if (mp[t[i]] <= 0) ok = false;
	}
	if (!ok) {
		cout << -1 << endl;
		return 0;
	}
	long long last = 0;
	long long sum = 0;
	long long n = s.length();
	for (int i = 0; i < (int)t.length(); i++) {
		int x = s.substr(last, n-last).find(t[i]);
		if (x == -1) {
			sum += n - last;
			x = s.find(t[i]);
			last = 0;
		}
		sum += x +1ll;
		
		last += x+1ll;
	}
	cout << sum;
	return 0;
}