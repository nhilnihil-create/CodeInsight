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
	int n,k;
	cin >> n >> k;
	int r, s, p;
	cin >> r >> s >> p;
	string ss,tmp;
	map<char, int>m;
	cin >> ss;
	string res = "";
	for (auto u : ss) {
		if (u == 'r')tmp = "p";
		else if (u == 's')tmp = "r";
		else tmp = "s";
		res += tmp;
	}
	int cnt = 0;
	for (int i = 0; i < n - k; i++) {
		if (res[i] == res[i + k]) {
			res[i + k] = 'o';
		}
	}
	for (auto q : res)m[q]++;

	ll ans = r * m['r'] + s * m['s'] + p * m['p'];
	cout << ans << endl;
	return 0;
}

