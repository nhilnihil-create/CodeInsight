#include"bits/stdc++.h"

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, n) for (int i = 1; i <= (int)(n); i++)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = long long;
using pi = pair<int, int>;
const ll INF = 1LL << 60;

int main() {
	int n, a, ans=0;
	cin >> n;
	map<int, int>mp;
	rep(i, n) {
		cin >> a;
		mp[a]++;
	}
	if (mp.size() == 1) {
		if (mp[0] == n)ans = true;
	}
	else if (mp.size() == 2) {
		if (n % 3 == 0) {
			if (mp[0] == n / 3)ans = true;
		}
	}
	else if (mp.size() == 3) {
		int x, y, z,tmp=0;
		auto p = mp.begin();
		x = (*p).first; p++;
		y = (*p).first; p++;
		z = (*p).first;
		tmp = x ^ y;
		tmp ^=z;
		if (tmp == 0 && mp[x] == mp[y] && mp[x] == mp[z] && mp[y] == mp[z])ans = true;
	}
	if (ans) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
	return 0;
}

