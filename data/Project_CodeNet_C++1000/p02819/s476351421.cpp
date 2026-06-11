#include<iostream>
#include <algorithm>
#include<vector>
using namespace std;
bool is_prime(long long j)
{
	for (int i = 2; i*i < j; i++)
	{
		if (j % i == 0)
		{
			return false;
		}
	}
	return true;
}
long long  solveitabdo(long long x)
{
	for (int  i = x; i < 1e9+7; i++)
	{
		if (is_prime(i))
		{
			return i;
		}
	}
}
int main()
{
	long long x;
	cin >> x;
	cout << solveitabdo(x);
}