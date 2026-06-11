#include"bits/stdc++.h"
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
const int mod = 1000000007;
const int inf = 1ll << 61;
typedef pair<int, int> P;
typedef pair<int, P>PP;
int a[300006];
int rv[300005];
signed main() {
	int n; cin >> n;
	rep(i, n)cin >> a[i];
	sort(a, a + n);
	vector<int>V;
	int now = a[0];
	int cnt = 0;
	rep(i, n + 1) {
		if (now != a[i]) {
			V.push_back(cnt);
			cnt = 1; now = a[i];
		}
		else cnt++;
	}
	sort(V.begin(), V.end());
	int m = V.size();
	rep(i, m)rv[i + 1] = V[i];
	rep(i, m)rv[i + 1] += rv[i];
	for (int K = 1; K <= n; K++) {
		if (K == 1)cout << n << endl;
		else {
			int lb = -1, ub = n / K + 1;
			while (ub - lb > 1) {
				int mi = (ub + lb) / 2;
				int sum = 0;
				int itr = upper_bound(V.begin(), V.end(), mi) - V.begin();
				sum = rv[itr] + (m - itr)*mi;
				if (sum < mi*K)ub = mi;
				else lb = mi;

			}
				cout << lb << endl;
		}
	}
}
