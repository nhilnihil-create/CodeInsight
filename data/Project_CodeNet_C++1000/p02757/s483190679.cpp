#include <bits/stdc++.h>
#define int long long
using namespace std;

int n,p,ans=0;
int a[200005],b[200005],c[10005];

int quick_power(int a,int b)
{
	int res=1;
	for (;b;b=b>>1,a=(a*a)%p)
	{
		if (b&1)  res=(res*a)%p;
	}
	return res;
}

signed main()
{
	cin>>n>>p;
	c[0]=1;
	
	for (int i=1;i<=n;i++)
	{
		char x;
		cin>>x;
		a[i]=x-'0';
	}
	if (p==2)
	{
		for (int i=1;i<=n;i++)
		{
			if (a[i]%2==0)  ans+=i;
		}
		cout<<ans<<endl;
		return 0;
	}
	else if (p==5)
	{
		for (int i=1;i<=n;i++)
		{
			if (a[i]==0||a[i]==5)  ans+=i;
		}
		cout<<ans<<endl;
		return 0;
	}
	for (int i=n;i>=1;i--)  b[i]=(b[i+1]+(a[i]*quick_power(10,n-i+1))%p)%p;
	for (int i=1;i<=n;i++)  c[b[i]]++;
	for (int i=0;i<=p-1;i++)  ans=ans+((c[i]*c[i]-c[i])/2);
	cout<<ans<<endl;
	
	return 0;
}