#include <bits/stdc++.h>

#define rep(i, first, to) for(int i = first; i < to; ++i)
#define REP(i, first, to) for(int i = first; i <= to; ++i)
#define MyDebug

#ifdef MyDebug
	#define debug(x) cout << #x << " : " << x << endl
	#define debugP(x) cout << x << endl
#else
	#define debug(x)
	#define debugP(x)
#endif

using namespace std;
typedef long long ll;

int a[20], s[(int)pow(2, 20)];
int m[200];
int n, q;
int j = 0;

bool dfs(int i, int s1) {
	if (i == n) {
		s[j++] = s1;
		//cout << s1 << endl;
		return false;
	}
	if (dfs(i + 1, s1 + a[i])) return false;
	if (dfs(i + 1, s1)) return false;
	return false;
}

void solve() {
	cin >> n;
	rep(i, 0, n) {
		cin >> a[i];
	}
	cin >> q;
	rep(i, 0, q) {
		cin >> m[i];
	}
	dfs(0, 0);
	bool isOk;
	sort(s, s + (int)pow(2, n));
	rep(k, 0, q) { 
		if (binary_search(s, s + (int)pow(2, n), m[k])) cout << "yes" << endl;
		else cout << "no" << endl;
	}
}

int main() {
	solve();
	return 0;
}