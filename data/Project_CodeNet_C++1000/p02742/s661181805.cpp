#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string>
#include<math.h>
#include<vector>
#include<iomanip>
using namespace std;

long long int gcd(long long int x, long long int y)
{
	if (y == 0) { return x; }
	return gcd(y, x % y);
}

int main(void)
{
	long long int h, w;
	cin >> h >> w;
	
	if (h == 1 || w == 1) { cout << 1 << endl; }
	else { cout << (h * w + 1) / 2 << endl; }
	return 0;
}
