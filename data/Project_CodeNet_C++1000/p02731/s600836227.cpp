#include <iostream>
#include <cmath>

using namespace std;

int main(void)
{
	int l;
	cin >> l;
	long double d = l / 3.0;
	printf("%.10Lf\n", d * d * d);

	return 0;
}