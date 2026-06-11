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
	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> p(m);
	for (int i = 0; i < m; i++) cin >> p[i].first >> p[i].second;

	for (int i = 0; i < 1000; i++) {
		int i_copy = i;
		vector<int> v_i;
		if (i_copy == 0) v_i.push_back(0);
		else {
			while (i_copy != 0) {
				v_i.push_back(i_copy % 10);
				i_copy /= 10;
			}
		}
		reverse(v_i.begin(), v_i.end());
		int keta = v_i.size();
		if (keta != n) continue;
		bool flag = true;
		for (int j = 0; j < m; j++) {
			if (v_i[p[j].first - 1] != p[j].second) flag = false;
		}
		if (flag) {
			cout << i << endl;
			return 0;
		}
	}
	cout << -1 << endl;
	return 0;
}