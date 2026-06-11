#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
long long int  m,t;
long long int a[200005];
int main()
{
	cin >> t;
	for (int i = 1; i <= t; i++)
	{
		cin >> a[i];
	}
	sort(a + 1, a + 1 + t);
	m = a[t];
	int j = t - 1;
	for (int i = (t - 2) / 2; i > 0; i--)
	{
		m += 2 * a[j--];
	}
	if (t % 2 == 1)
	{
		m += a[j];
	}
	cout << m;
}
