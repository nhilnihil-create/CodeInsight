#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define ss(x) (int) x.size()
#define cat(x) cerr << #x << " = " << x << endl
#define rep(i, j, n) for (int i = j; i <= n; ++i)
#define per(i, j, n) for (int i = n; j <= i; --i)

using ll = long long;
using namespace std;

const int N = 2e5 + 100;

int n, a[N][2];
queue <int> q;

int s(int x) {
	return a[(x - 1 + n) % n][1] + a[(x + 1) % n][1];
}

void nie() {
	printf ("-1\n");
	exit(0);
}

int main() {
	scanf ("%d", &n);
	rep(j, 0, 1)
		rep(i, 0, n - 1)
			scanf ("%d", &a[i][j]);
			
	rep(i, 0, n - 1) {
		if (a[i][0] > a[i][1]) nie();
		if (a[i][1] > a[i][0] && s(i) < a[i][1]) q.push(i);
	}
		
	ll moves = 0;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		int cnt = (a[x][1] - a[x][0]) / s(x);
		moves += cnt;
		a[x][1] -= s(x) * cnt;
		
		int prv = (x - 1 + n) % n, nxt = (x + 1) % n;
		if (s(nxt) < a[nxt][1] && a[nxt][1] > a[nxt][0]) q.push(nxt);
		if (s(prv) < a[prv][1] && a[prv][1] > a[prv][0]) q.push(prv);
	}
	rep(i, 0, n - 1) if (a[i][0] != a[i][1]) nie();
	printf ("%lld\n", moves);
	return 0;
}
