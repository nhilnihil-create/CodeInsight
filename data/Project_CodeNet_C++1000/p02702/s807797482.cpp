#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	string s;
	cin >> s;
	vector<ll>mod1(s.length(),0);
	for (int i = 0; i < s.length(); i++) {
		if (i == 0)mod1.at(i) = 1;
		else mod1.at(i) = mod1.at(i-1) * 10 % 2019;
	}
	vector<ll>mod(s.length(),0);
	for (int i = 0; i < s.length(); i++) {
		int x = s.at(s.length() - 1 - i) - '0';
		if (i == 0)mod.at(i) = x * mod1.at(i);
		else {
			mod.at(i) = mod.at(i - 1) + x * mod1.at(i);
			mod.at(i) %= 2019;
		}
	}
	map<ll, ll>mods;
	mods[0] = 1;
	for (int i = 0; i < mod.size(); i++) {
		if (mods.count(mod.at(i)))mods.at(mod.at(i))++;
		else mods[mod.at(i)] = 1;
	}
	ll ans = 0;
	for (auto a : mods) {
		if (a.second == 1)continue;
		else ans += a.second * (a.second - 1) / 2;
	}
	cout << ans << endl;
}