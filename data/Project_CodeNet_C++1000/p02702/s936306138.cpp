#pragma GCC optimize("Ofast")
#include <bits/stdc++.h> 
using namespace std;
 
typedef long long ll;
 
string int_to_string(int x) {
    stringstream ss;
	ss << x;
	string ni = ss.str();
	return ni;
}

int mod = 1e9 + 7;
ll power(ll a, ll b) {
	ll ans = 1;
	while (b) {
		if(b & 1) {
			ans = (ans * a) % mod;
		}
		a = (a * a) % mod;
		b /= 2;
	}
	return ans;
}
 
int main() { 
	string s;
	cin >> s;
	int n = (int)s.size();
	//18171  81712114
	//18171
	vector<ll> m(2019);
	ll ans = 0;
	ll p = 1;
	ll x = 0;
	m[0] = 1;
	for (int i = n - 1; i >= 0; --i) {
		x += p * (s[i] - '0');
		ans += m[x % 2019];
		p = (p * 10) % 2019;
		m[x % 2019]++;
		x = x % 2019;
	}
	cout << ans;
}





	
