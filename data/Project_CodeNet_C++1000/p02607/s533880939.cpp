#include <bits/stdc++.h>
 
using namespace std;

#ifdef ARTEM
	#define deb(x) x
#else
	#define deb(x)
	const int LIMIT = 2 * int(1e5) + 123;
#endif

void solve();

int main() {
	solve();
}

/* ================ actual code starts here ================ */

void solve() {
	int n;
	scanf("%d", &n);

	int ans = 0;
	for(int i = 0, x; i < n; i++) {
		scanf("%d", &x);
		ans += int(!(i & 1) && (x & 1));
	}
	printf("%d\n", ans);
}