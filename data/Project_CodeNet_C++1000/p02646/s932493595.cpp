#include <bits/stdc++.h>
using namespace std;
int main() {
	int a, v, b, w, t;
	cin >> a >> v >> b >> w >> t;
	if (v <= w) puts("NO");
	else {
		if (abs(a - b) <= 1ll * (v - w) * t) puts("YES");
		else puts("NO");
	}
	return 0;
}