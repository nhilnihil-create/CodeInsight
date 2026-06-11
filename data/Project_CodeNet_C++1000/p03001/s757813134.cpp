#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
int  main()
{


	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	double a, b, x, y;
	cin >> a >> b >> x >> y;
	if ((x + x ) == a && (y + y) == b)
		printf("%0.12f 1", a * b / 2.0);
	else
		printf("%0.12f 0", a * b / 2.0);

}