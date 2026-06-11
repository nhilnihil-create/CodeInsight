#include <bits/stdc++.h>

using namespace std;

const long long int MOD = 1e9 + 7;
long long int mypow(long long int x,long long int n)
{
	long long int res = 1;
	while(n>0)
	{
		if(n%2==1)
		{
			res = ((res%MOD)*(x%MOD)%MOD)%MOD;
			res%=MOD;
		}
		x = ((x%MOD)*(x%MOD)%MOD)%MOD;
		x%=MOD;
		n/=2;
	}
	return res;
}
long long int f[2000001];

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	long long int res = 0;
	long long int x,y;

	cin >> x >> y;

	f[0] = 1;
	for(int i=1;i<=2000000;i++)
	{
		f[i] = ((f[i-1]%MOD)*(i%MOD)%MOD)%MOD;
		f[i]%=MOD;
	}

	for(int a=0;a<=x;a++)
	{
		int b = x - a;
		if(b%2!=0)
		{
			continue;
		}
		b/=2;
		if(2*a + b == y)
		{
			long long int ways = f[a+b];
			ways = ((ways%MOD)*(mypow(f[a],MOD-2)%MOD)%MOD)%MOD;
			ways%=MOD;
			ways = ((ways%MOD)*(mypow(f[b],MOD-2)%MOD)%MOD)%MOD;
			ways%=MOD;
			res = ((res%MOD) + (ways%MOD)%MOD)%MOD;
			res%=MOD;			
		}
	}

	cout << res << '\n';

	return 0;
}
