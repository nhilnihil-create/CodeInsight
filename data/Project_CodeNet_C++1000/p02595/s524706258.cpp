#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n,d;
	cin >> n >> d;
	int ans = 0;
	while(n--) {
		long long x,y;
		cin >> x >> y;
		x = abs(x);
		y = abs(y);
		long long q = ceil(sqrt(x*x + y*y));
		if(q <= (long long)d) ans++;
	}
	printf("%d", ans);
	return 0;
}
