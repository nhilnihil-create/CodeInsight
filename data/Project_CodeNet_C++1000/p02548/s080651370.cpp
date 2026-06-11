#include<bits/stdc++.h>
#define ll long long
#define MAX 1000005
#define MOD (ll)(1e9+7)
#define ex(k) (a*(b-n)+(a-b)*(k)-(k)*(k))
using namespace std;

int fac[MAX];

void sieve()	{
	memset(fac,0,sizeof(fac));
	for(int i=1; i<MAX; i++)	{
		for(int j=i; j<MAX; j+=i)	fac[j]++;
	}
}

void solve()	{
	sieve();
	int n;
	cin >> n;
	int ans=0;
	for(int i=1; i<n; i++)	{
		ans+=fac[i];
	}
	cout << ans << endl;
}

int main()	
{
	int t=1;
	//cin >> t;
	for(int i=1; i<=t; i++)	{
		solve();
	}
	return 0;
}