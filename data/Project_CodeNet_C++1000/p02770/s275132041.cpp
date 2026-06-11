#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int k,q;
	cin>>k>>q;
	long long d[k];
	for (int i = 0; i < k; ++i)
	{
		cin>>d[i];
	}
	for (int i = 0; i < q; ++i)
	{
		long long n,x,m;
		cin>>n>>x>>m;
		long long a[k],z=0LL,s=0LL;
		for (int j = 0; j < k; ++j)
		{
			a[j]=d[j]%m;
			if (a[j]==0)
			{
				++z;
			}
			s+=a[j];
		}
		s*=(n-1LL)/(long long)k;
		s+=x%m;
		z*=(n-1LL)/(long long)k;
		for (int j = 0; j < (int)(n-1)%k; ++j)
		{
			if (a[j]==0)
			{
				++z;
			}
			s+=a[j];
		}
		z+=s/m;
		cout<<n-z-1LL<<endl;
	}
	return 0;
}
