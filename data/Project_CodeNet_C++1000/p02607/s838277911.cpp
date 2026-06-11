#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define ss(x) (int) x.size()
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl
#define rep(i, j, n) for (int i = j; i <= n; ++i)
#define per(i, j, n) for (int i = n; j <= i; --i)
#define all(x) x.begin(), x.end()
#define ld long double

using namespace std;	

int main() {	
	int n, a, ans = 0;
	scanf ("%d", &n);
	rep(i, 1, n) {
		scanf ("%d", &a);
		ans += ((i & 1) & (a & 1));
	}
	printf ("%d\n", ans);
	
	return 0;
}
