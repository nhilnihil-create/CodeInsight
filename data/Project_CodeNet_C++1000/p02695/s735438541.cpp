#include <bits/stdc++.h>
#define pb		  push_back
#define pairs	  pair<int, int>
#define vi		  vector<int>
#define vb		  vector<bool>
#define vii		  vector<pairs>
#define lb		  lower_bound
#define ub		  upper_bound
#define lli		  long long int
#define endl	  '\n'
#define FastInput ios_base::sync_with_stdio(false), cin.tie(NULL);
#define Cases	  cout << "Case " << ++Case << ": ";
#define __test    \
	int tt;       \
	int Case = 0; \
	cin >> tt;    \
	while (tt--)
#define read(x)	 freopen(x, "r", stdin)
#define write(x) freopen(x, "w", stdout)
#define InputArray(a, n)        \
	for (int i = 0; i < n; i++) \
		cin >> a[i];
#define CopyArray(a, temp, n)   \
	for (int i = 0; i < n; i++) \
		temp[i] = a[i];
#define PrintArray(a, n)        \
	for (int i = 0; i < n; i++) \
		cout << a[i] << " ";    \
	cout << endl;
using namespace std;

int n, m, q;
vi a, b, c, d;
vi A;
int ans = 0;

int check() {
	int res = 0;
	for (int i = 0; i < q; i++) {
		if (A[b[i]] - A[a[i]] == c[i]) {
			res += d[i];
		}
	}
	return res;
}

void dfs(int i, int cur) {
	if (i >= n) {
		ans = max(ans, check());
		return;
	}
	for (int j = cur; j <= m; j++) {
		A.push_back(j);
		dfs(i + 1, j);
		A.pop_back();
	}
}


int main() {
	cin >> n >> m >> q;
	a = b = c = d = vi(q);
	for (int i = 0; i < q; i++) {
		cin >> a[i] >> b[i] >> c[i] >> d[i];
		a[i]--;
		b[i]--;
	}

	dfs(0, 1);

	cout << ans << endl;

	cerr << "time = " << (clock() / CLOCKS_PER_SEC) << " sec" << '\n';
	return 0;
}


