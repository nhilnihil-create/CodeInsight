#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
long long c[5];
long long a[5];
int main()
{
	for (int i = 1; i <= 4; i ++)
	cin >> a[i];
	c[1] = a[1] * a[3];
	c[2] = a[1] * a[4];
	c[3] = a[2] * a[3];
	c[4] = a[2] * a[4];
	sort (c + 1, c + 5);
	cout << c[4];
	return 0;
}