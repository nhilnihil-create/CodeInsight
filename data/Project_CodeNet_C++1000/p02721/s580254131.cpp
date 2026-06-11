#include <iostream>
using namespace std;

int dp1[200005],dp2[200005],rest[200005];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,k,c;
	cin >> n >> k >> c;
	string a = " ",b;
	cin >> b;
	a += b;
	for (int i = 1; i <= n; i++)
	{
		if( a[i] == 'o' )
		{
			dp1[i] = dp1[i-1] + 1;
			rest[i] = c;
			for (int j = 1; j <= c; j++)
			{
				if( i + j > n ) break;
				dp1[i+j] = dp1[i];
				rest[i+j] = c - j;
			}
			i += c;
		}else dp1[i] = dp1[i-1],rest[i] = 0;
	} 
	for (int i = n; i >= 1; i--)
	{
		if( a[i] == 'o' )
		{
			dp2[i] = max(dp2[i+1],dp2[min(n+1,i+c+1)] + 1);
		}else dp2[i] = dp2[i+1];
	}
	for (int i = 1; i <= n; i++)
	{
		if( a[i] == 'o' )
		{
			if( dp1[i-1] + dp2[min(max(i-1+rest[i-1]+1,i+1),n+1)] < k )
			{
				cout << i << '\n';
			}
		}
	}
	return 0;
}
