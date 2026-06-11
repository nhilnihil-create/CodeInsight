#include<iostream>
#include <algorithm>
#include<map>
using namespace std;
long long gcdback(long long  a, long long b)
{
	return __gcd(a, b);
}
int solveitabdo(long long x, long long y)
{
	map<long long, int>max1;
	long long gcdnum = gcdback(x, y);
	for (long long i = 2; i*i <= gcdnum; i++)
	{
		while (gcdnum % i == 0)
		{
			max1[i]++;
			gcdnum /= i;
		}
	}
	if (gcdnum != 1)
	{
		max1[gcdnum]++;
	}
	return max1.size() + 1;
}
int main()
{
	long long x, y;
	cin >> x >> y;
	cout<<solveitabdo(x, y);
}
