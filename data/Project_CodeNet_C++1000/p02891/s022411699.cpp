#pragma GCC optimize("Ofast", "unroll-loops")

#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
	const auto half = [](int a) {return a >> 1; };
	const auto halfl = [](ll a) { return a >> 1; };
	string s; cin >> s;
	int k; cin >> k;
	bool all_same = true;
	for (int i = 0; i < s.length() - 1; ++i)
		all_same &= s[i] == s[i + 1];
	if (all_same)
		cout << halfl((ll)(s.length()) * k) << endl;
	else {
		vector<int> separate;
		int l = 0, ptr = 1;
		while (l < s.length()) {
			if (ptr == s.length() || s[ptr] != s[ptr - 1]) {
				separate.push_back(ptr - l);
				l = ptr;
			}
			++ptr;
		}
		ll res = 0;
		if (s[0] != s[s.length() - 1]) {
			for (auto i : separate)
				res += (ll)k * half(i);
			cout << res << endl;
		}
		else {
			int sz = separate.size();
			res += half(separate[0]);
			res += half(separate[sz - 1]);
			for (int i = 1; i < sz - 1; ++i)
				res += (ll)k * half(separate[i]);
			int b = separate[0] + separate[sz - 1];
			res += (k - 1LL) * half(b);
			cout << res << endl;
		}
	}
	return 0;
}