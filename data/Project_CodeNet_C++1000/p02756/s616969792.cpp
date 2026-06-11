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

int main() {
	string s;
	int q;
	cin >> s >> q;
	string front, back;
	back = s;
	bool forb = 1;
	for (int i = 0; i < q; i++) {
		int t;
		cin >> t;
		if (t == 1) {
			if (forb) forb = 0;
			else forb = 1;
		}
		else {
			int f;
			char c;
			cin >> f >> c;
			if (f == 1) {
				if (forb) front.push_back(c);
				else back.push_back(c);
			}
			else {
				if (forb) back.push_back(c);
				else front.push_back(c);
			}
		}
	}
	if (forb) {
		reverse(front.begin(), front.end());
		front += back;
		cout << front << endl;
	}
	else {
		reverse(back.begin(), back.end());
		back += front;
		cout << back << endl;
	}
	return 0;
}