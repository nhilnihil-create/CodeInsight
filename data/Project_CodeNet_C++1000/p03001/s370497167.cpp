#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main() {
	double W, H, x, y;
	cin >> W >> H >> x >> y;
	double ans = W * H / 2.0;
	int ok = 0;
	if (x == W / 2 && y == H / 2) ok = 1;
	printf("%.10f %d\n", ans, ok);
	return 0;
}
