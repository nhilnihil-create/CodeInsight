//所要時間3～4時間 再帰に慣れてなかったので脳がバグった

#include "bits/stdc++.h"
using namespace std;
#define rep(i, n) for(int i=0;i<(n);i++)
int n;
const double root3 = 1.73205080768877;

void koch(double x0, double y0, double x1, double y1, int n)
{
	if (n == 0) cout <<fixed << setprecision(8) << x0 << " " << y0 << endl;
	else
	{
		double c1[2], c2[2], c3[2];
		 c1[0] = 2 * x0 / 3 + x1 / 3;
		 c1[1] = 2 * y0 / 3 + y1 / 3;
		 c2[0] = (x0 + x1) / 2 - root3 * (y1 - y0) / 6;
		 c2[1] = (y0 + y1) / 2 + root3 * (x1 - x0) / 6;
		 c3[0] = x0 / 3 + 2 * x1 / 3;
		 c3[1] = y0 / 3 + 2 * y1 / 3;
		 koch(x0, y0, c1[0], c1[1], n - 1);
		 koch(c1[0], c1[1], c2[0], c2[1], n - 1);
		 koch(c2[0], c2[1], c3[0], c3[1], n - 1);
		 koch(c3[0], c3[1], x1, y1, n - 1);

	}
}
int main()
{	
	cin >> n;	
	koch(0, 0, 100, 0, n);
	cout << fixed << setprecision(8) <<100<<" "<<0 << endl;;
	return 0;
}
