#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll f(ll x) {
	if (x == 0)return 0;
	ll y = (1 + x) * x / 2;
	return y;
}
int main() {
	string s;
	cin >> s;
	if (s.at(0) == '>')s = '<' + s;
	if (s.at(s.length() - 1) == '<')s += '>';

	vector<ll>a;
	ll l = 0;
	ll r = 0;
	bool lr = false;
	for (int i = 0; i < s.length(); i++) {
		if (lr == false && s.at(i) == '<')l++;
		else if (lr == false && s.at(i) == '>') {
			lr = true;
			r++;
		}
		else if (lr == true && s.at(i) == '>')r++;
		else if (lr == true && s.at(i) == '<') {
			a.push_back(l);
			a.push_back(r);
			l = 1;
			r = 0;
			lr = false;
		}
	}
	a.push_back(l);
	a.push_back(r);
	//for (int i = 0; i < a.size(); i++)cout << a.at(i) << " ";
	vector<ll>ans;
	for (ll i = 0; i < a.size() / 2; i++) {
		ll x = a.at(0 + i * 2);
		ll y = a.at(1 + i * 2);
		if (x > y)swap(x, y);
		x--;
		ans.push_back(x);
		ans.push_back(y);
	}
	ll an = 0;
	for (int i = 0; i < ans.size(); i++)an += f(ans.at(i));
	cout << an << endl;
}