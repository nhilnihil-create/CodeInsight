#include <bits/stdc++.h>

#define PI 3.14159265359

using namespace std;
using ll = long long;
using pint = pair<int, int>;

int main() {
	int A, B, H, M;
	cin >> A >> B >> H >> M;

	double rad = abs(((2 * PI / 720.0) * (H * 60.0 + M) - (2 * PI / 60.0) * M));
	double ans = A * A + B * B - 2 * A * B * cos(rad);
	ans = sqrt(ans);

	cout << fixed << setprecision(10) << ans << endl;
	return 0;
}
