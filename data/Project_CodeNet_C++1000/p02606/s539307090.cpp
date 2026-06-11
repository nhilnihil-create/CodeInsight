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
	int l, r, d;
	scanf("%d%d%d", &l, &r, &d);
	printf("%d\n", r / d - (l - 1) / d);
}