#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	int a, b;
	double c, d;
	cin >> a >> b;
	c = a;
	d = b;

	printf("%d %d %.8lf\n", a/b, a%b, c/d);
}