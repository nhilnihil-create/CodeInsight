#include<bits/stdc++.h>
using namespace std;

long long int n,i,ans,d,sq,x;

signed main()
{
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n;ans=2;
	if (n==2) 
	{
		cout<<1;return 0;
	}
	sq=trunc(sqrt(n));
	for (i=2;i<sq+1;i++) if (n%i==0)
	{
		x=n;
		while (x%i==0) x=x/i;
		if ((x-1)%i==0) ans++;
		x=n;
		while (x%(n/i)==0) x=x/(n/i);
		if ((x-1)%(n/i)==0 && i!=n/i) ans++;
	}
	n--;sq=trunc(sqrt(n));
	for (i=2;i<sq+1;i++) if (n%i==0)
	{
		ans=ans+2;
		if (i==n/i) ans--;
	}
	cout<<ans;
}
