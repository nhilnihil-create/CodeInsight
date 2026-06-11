#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
int  main()
{


	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, x;
	cin >> n >> x;
	int a;
	int count = 1;
	int sum = 0;
	for (int i = 0; i < n; i++)
	{

		cin >> a;
		sum += a;
		if (sum <= x)
			count++;
		else
			break;
	}
	cout << count;

}