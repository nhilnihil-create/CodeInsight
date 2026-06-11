#include <bits/stdc++.h>
using namespace std;

/*
提出前に確認!
- setとmultisetを間違えない
*/

int	main(void)
{
	long long x, k, d;
	cin >> x >> k >> d;
	//x反転しても一般性を失わない
	x = abs(x);
	//がんばっても0を越せないならそこが限界
	if (x / d >= k) cout << x - d * k << endl;
	else if ((x / d) % 2 == k % 2) cout << x - x / d * d << endl;
	else cout << (x / d + 1) * d - x << endl;
	return (0);
}
