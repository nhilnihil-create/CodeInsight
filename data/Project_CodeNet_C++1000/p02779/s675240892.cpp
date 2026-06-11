//empty sockets
#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long int n, i;
	cin >> n;
	long long int a[n];
	for (i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	sort(a, a + n);
	int flag = 1;
	for (i = 0; i < n; i++)
	{
		if (a[i] == a[i + 1])
		{
			flag = 0;
			break;
		}
	}
	if (flag == 1)
	{
		cout << "YES" << endl;
	}
	else
	{
		cout << "NO" << endl;
	}
	return 0;
}

