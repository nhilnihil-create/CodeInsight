#include <iostream>
#include <cstdio>

using namespace std;




int main()
{
	long a, b;
	long d, r;
	double f;
	
	cin >> a >> b;
	d = a / b;
	r = a % b;
	f = 1.000000 * a / b;
	cout << d << " " << r << " ";
	printf("%.5lf\n", f);
	
	return 0;
}