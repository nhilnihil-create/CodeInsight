#include<bits/stdc++.h>

using namespace std;

long long ans;
int a[200010];
int n;
//int d[200010];
int main()
{
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for(int i = 2; i <= n; i++)
	{
		if(a[i] < a[i-1])
		{
			ans += (a[i-1] - a[i]);
			a[i] = a[i-1];
		}
	}
	cout << ans << endl;
	return 0;
}