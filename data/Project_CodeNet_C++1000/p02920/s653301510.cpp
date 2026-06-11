#include"bits/stdc++.h"
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
typedef pair<int, int> P;
const long long mod = 1000000007;
const double eps = 1e-11;
const int inf = 1ll << 61;
vector<int>v;
int comb[25][25];
int rwc[20];
int rk[300000];
signed main() {
	int n; cin >> n;
	map<int, int>M1, M2;
	rep(i, 1 << n) {
		int c; cin >> c; v.push_back(c);
		M1[c]++;
	}
	int cnt = 0;
	for (auto i = M1.begin(); i != M1.end(); i++) {
		M2[i->first] = cnt; cnt++;
		if (i->second > (1 << (n - 1))) {
			cout << "No" << endl; return 0;
		}
	}
	rep(i, 1 << n) {
		v[i] = M2[v[i]];
		rk[v[i]]++;
	}

	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());

	int T = v[0];
	for (int i = T; i >= 1; i--) {
		rk[i - 1] += rk[i];
	}

	comb[0][0] = 1;
	rep(i, 20){rep(j, i + 1) {
		comb[i + 1][j] += comb[i][j];
		comb[i + 1][j + 1] += comb[i][j];
	}}
	rep(i, n)rwc[i] = comb[n][i];
	rep(i, n)rwc[i+1] += rwc[i];
	rep(i, n) {
		if (T-i<0||rwc[i] < rk[T - i]) {
			cout << "No" << endl;
			return 0;
		}
	}

	cout << "Yes" << endl;
}