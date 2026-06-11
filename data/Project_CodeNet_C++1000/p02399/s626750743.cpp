#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
	int a, c;

	cin >> a >> c;
	printf("%d %d %.5f\n", a / c, a % c, a / (c * 1.0));

	return(0);
}