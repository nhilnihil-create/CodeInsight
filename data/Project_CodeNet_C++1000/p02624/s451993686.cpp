#include<iostream>
#include <algorithm>
#include<map>
using namespace std;
int arr1[10000005];
long long  solveitabdo(long long x)
{
	for (long long i = 1; i <= x; i++)
	{
		for (long long j = i; j <= x; j += i)
		{
			arr1[j]++;
		}
	}
	long long back1 = 0;
	for (long long i = 1; i <= x; i++)
	{
		back1 += arr1[i] * i;
	}
	return back1;
}
int main()
{
	long long x;
	cin >> x ;
	cout<<solveitabdo(x);
}
