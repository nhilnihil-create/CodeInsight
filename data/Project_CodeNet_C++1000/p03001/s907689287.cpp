#include <bits/stdc++.h>
using namespace std;
int main(void)
{
	long long w, h, x, y;
	cin >> w >> h >> x >> y;
	printf("%.08Lf ", (long double)w*h/2.0);
	if (2*x == w && 2*y == h)
		printf("1\n");
	else
		printf("0\n");
	return 0;

}
