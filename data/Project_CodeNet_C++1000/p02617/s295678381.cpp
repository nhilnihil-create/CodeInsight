#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
	long long n, l, r,sum=0;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		sum += i * (n - i + 1);
	}
	for (int i = 1; i < n; i++)
	{
		cin >> l >> r;
		if (l > r)
			swap(l, r);
		sum -= l * (n - r + 1);
	}
	cout << sum << endl;
}
