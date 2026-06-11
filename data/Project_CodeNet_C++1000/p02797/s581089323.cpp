#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 1e9;
const int MOD = 1000000007;
const double PI = acos(-1);
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

void solve() {
	int n, k, s;
	cin >> n >> k >> s;
	vector<int> v(n);
	rep(i, k) {
		v[i] = s;
	}
	int cur = s;
	if (cur == INF) cur = 1;
	else cur++;
	for (int i = k; i < n; i++) v[i] = cur;
	rep(i,n) {
		if (i != 0) cout << " ";
		cout << v[i];
	}
}

int main() {
	solve();
	return 0;
}