#include <bits/stdc++.h>

using namespace std;

const long long int MOD = 1e9 + 7;

vector <long long int> prime;

long long int mypow(long long int x,long long int n)
{
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

void eratos(void)
{
	bool isprime[100001];
	memset(isprime,true,sizeof(isprime));
	for(int i=2;i<=100000;i++)
	{
		if(isprime[i])
		{
			prime.push_back(i);
			for(int j=2*i;j<=100000;j+=i)
			{
				isprime[j] = false;
			}
		}
	}
}

long long int phi(long long int a)
{
	map <long long int,long long int> cnt;
	long long int tot = 1;
	for(int j=0;j<prime.size();j++)
	{
		if(a==1)
		{
			break;
		}
		while(1)
		{
			if(a%prime[j]!=0)
			{
				break;
			}
			a/=prime[j];
			cnt[prime[j]]++;
		}
	}
	if(a!=1)
	{
		cnt[a]++;
	}
	for(auto it : cnt)
	{
		long long int val = mypow(it.first,it.second) - mypow(it.first,it.second-1);
		val%=MOD;
		if(val < 0)
		{
			val += MOD;
		}
		tot*=val;
		tot%=MOD;
	}
	return tot;	
}
int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	long long int k,n;

	cin >> n >> k;

	eratos();

	long long int res = 0;

	for(long long int g=k;g>=1;g--)
	{
		long long int num = mypow(k/g,n);
		num = ((num%MOD)*(phi(g)%MOD)%MOD);
		res = ((res%MOD) + (num%MOD)%MOD);
		res%=MOD;
	}

	cout << res << '\n';

	return 0;
}