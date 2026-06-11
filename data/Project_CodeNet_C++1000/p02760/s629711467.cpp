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
	vector<vector<int>> a(3, vector<int>(3));
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> a[i][j];
		}
	}
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int b;
		cin >> b;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (a[i][j] == b) a[i][j] = 0;
			}
		}
	}
	bool flag = false;
	for (int i = 0; i < 3; i++) {
		if (a[i][0] == 0 && a[i][1] == 0 && a[i][2] == 0) flag = true;
		if (a[0][i] == 0 && a[1][i] == 0 && a[2][i] == 0) flag = true;
	}
	if (a[0][0] == 0 && a[1][1] == 0 && a[2][2] == 0) flag = true;
	if (a[0][2] == 0 && a[1][1] == 0 && a[2][0] == 0) flag = true;
	if (flag) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}