#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	long cnt = 0, i = 0, a, c, b, j, x, y, r, H, W;
	double z;
	cin >> a >> b;
	x = a / b;
	y = a%b;
	z = (double)a / b;
	printf("%ld %ld %1.5f\n", x, y, z);
}