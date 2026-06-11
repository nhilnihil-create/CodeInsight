#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)

int  main()
{
	long W,H,x,y; cin >> W >> H >> x >> y;

	long double area = (double)H*W;
	long double a,b;
	a = (long double)min((long double)area - ((H-y) * W), (long double)(H-y) * W);
	b = (long double)min((long double)area - (H * (W-x)), (long double)H * (W-x));
	long double c = (long double)H * W / 2;

	printf("%Lf ", (long double)max({a, b, c}));

	if ((long double)max({a, b, c}) == a || (long double)max({a, b, c}) == b)
	{
		if (a == b)
			cout << 1;
		else
			cout << 0;
	}
	else
		cout << "0\n";
	return (0);
}
