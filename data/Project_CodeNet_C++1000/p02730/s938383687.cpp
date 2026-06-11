#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<queue>
#include<stack>
#include<set>
#include<algorithm>
#include<utility>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
const int INF = 1001001001;

ll pow_mod(ll x, ll y) {
	ll res = 1;
	for (ll i = 0; i < y; i++) res = res * x % mod;
	return res;
}

ll gcd(ll x, ll y) {
	if (y == 0) {
		return x;
	}
	return gcd(y, x % y);
}

bool kaibun(string s) {
	string a = s;
	reverse(a.begin(), a.end());
	if (a == s) return true;
	else return false;
}

int main() {
	string s;
	cin >> s;
	int n = s.size();
	string a, b;
	a = s.substr(0, (n - 1) / 2);
	b = s.substr((n + 3) / 2 - 1, (n - 1) / 2);
	if (kaibun(s) && kaibun(a) && kaibun(b)) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}