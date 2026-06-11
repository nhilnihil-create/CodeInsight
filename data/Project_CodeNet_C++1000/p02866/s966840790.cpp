#include <bits/stdc++.h>
     
using namespace std;

const long long int MOD = 998244353;
int cnt[100000];
long long int mypow(long long int x,long long int n)
{
	if(x==0)
	{
		return 0;
	}
	long long int res = 1;
	while(n>0)
	{
		if(n%2==1)
		{
			res = ((res%MOD)*(x%MOD)%MOD);
			res%=MOD;
		}
		x = ((x%MOD)*(x%MOD)%MOD);
		x%=MOD;
		n/=2;
	}
	return res;
}
int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n,t;

	memset(cnt,0,sizeof(cnt));
	cin >> n;
	int Max = 0;
	for(int i=0;i<n;i++)
	{
		cin >> t;
		if(i==0 && t!=0)
		{
			cout << 0 << '\n';
			return 0;
		}
		cnt[t]++;
		Max = max(Max,t);
	}

	if(cnt[0]!=1)
	{
		cout << 0 << '\n';
		return 0;
	}

	long long int res = 1;

	for(int i=1;i<=Max;i++)
	{
		res = ((res%MOD)*(mypow(cnt[i-1],cnt[i])%MOD)%MOD);
		res%=MOD;
	}

	cout << res << '\n';

	return 0;
}
