#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long W, H, x, y;
	cin >> W >> H >> x >> y;

	double ans = (double)W * H / 2;
	int ans1 = 0;
	if( W == x * 2 && H == y * 2 ) ans1 = 1;

	cout << fixed << setprecision(12) << ans << " " << ans1 << endl;
}
