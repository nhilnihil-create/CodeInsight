#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
int  main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, a;
	cin >> n >> a;
	int l, r;
	l = a ;
	r = n + a - 1;
	int sum = 0;
	if (l >= 0 && r >= 0)
		l++;
	else if (l < 0 && r < 0)
		r--;

	//cout << l << r << endl;

	for (int i = l; i <= r; i++)
	{
		sum += i;
	}
	cout << sum;
}