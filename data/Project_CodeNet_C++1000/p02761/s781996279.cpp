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

string int_to_string(int x,int n) {
	string res;
	int y = 10;
	for (int i = 0; i < n; i++) {
		res.push_back('0' + (x % y) / (y / 10));
		y *= 10;
	}
	reverse(res.begin(), res.end());
	return res;
}
int main() {
	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> p(m);
	if (m > 0) {
		for (int i = 0; i < m; i++) {
			int s, c;
			cin >> s >> c;
			p[i] = make_pair(s, c);
		}
	}

	if (n == 1) {
		for (int i = 0; i < 10; i++) {
			bool flag = true;
			for (int j = 0; j < m; j++) {
				if (p[j].first != 1) {
					flag = false;
					break;
				}
				if (p[j].second != i) flag = false;
			}
			if (flag) {
				cout << i << endl;
				return 0;
			}
		}
		cout << -1 << endl;
		return 0;
	}

	int begin = 1;
	for (int i = 0; i < n - 1; i++) begin *= 10;
	for (int i = 10; i < 1000; i++) {
		if (i / begin > 0 && i / begin < 10) {
			string s = int_to_string(i, n);
			bool flag = true;
			for (int j = 0; j < m; j++) {
				if (s[p[j].first - 1] != '0' + p[j].second) {
					flag = false;
					break;
				}
			}
			if (flag) {
				cout << i << endl;
				return 0;
			}
		}
	}
	cout << -1 << endl;
	return 0;
}