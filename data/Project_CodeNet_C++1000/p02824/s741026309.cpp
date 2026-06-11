/*
ID: yzshang1
LANG: C++11
TASK:
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define pb push_back
#define mp make_pair
#define lsh(i) (1 << (i))
#define lshll(i) (1LL << (i))
#define repn(i, n) for (int (i) = 1; (i) <= (int)n; (i)++)
#define rep(i, n) for (int (i) = 0; (i) < (int)n; (i)++)
#define int long long
const int INF = 0x3f3f3f3f;
const long double EPS = 1e-6;
const int N = 100010;
LL n, m, v, p;
LL a[N];
bool check(int x) {
//	cerr << "CHECK " << x << endl; 
	LL totalVote = 0;
	if (x <= p) return true;
	else if (a[x] + m < a[p]) return false;
	else {
		totalVote += (p - 1) * m;
		totalVote += (n - x + 1) * m;
		for (int i = p; i < x; i++) totalVote += (a[x] + m - a[i]);
	//	cerr << totalVote << endl;
		return totalVote >= m * v;
	}
}
main() {
	cin >> n >> m >> v >> p;
	repn(i, n) cin >> a[i];
	sort(a + 1, a + n + 1, [](LL x, LL y) {
		return x > y;
	});
	int L = 0, R = n + 1;
	while (L + 1 < R) {
		int mid = (L + R) >> 1;
		if (check(mid)) L = mid;
		else R = mid;
	}
	int ans = 0;
	repn(i, n) if (a[i] < a[L]) break; else ans++;
	cout << ans << endl; 
	return 0;
}