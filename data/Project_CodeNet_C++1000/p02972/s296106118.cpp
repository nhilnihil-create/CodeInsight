#include <bits/stdc++.h>
#define int long long
using namespace std;

int n,len=0;
int a[200005],b[200005],ans[200005];

signed main()
{
	cin>>n;
	for (int i=1;i<=n;i++)  cin>>a[i];
	for (int i=n;i>=1;i--)
	{
		int sumv=0;
		for (int j=2*i;j<=n;j+=i)  sumv=(sumv+b[j])%2;
		
		if (sumv==a[i])  b[i]=0;
		else b[i]=1;
	}
	for (int i=1;i<=n;i++)
	{
		if (b[i]==1)  ans[++len]=i;
	}
	cout<<len<<endl;
	for (int i=1;i<=len;i++)  cout<<ans[i]<<' ';
	cout<<endl;
	
	return 0;
}
