#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int a[n+1],i,j,k,ans=0;
	for(int i=1; i<=n; i++)	cin>>a[i];
	sort(a+1,a+n+1);
	for(i=1; i<n-1; i++)
		for(j=i+1; j<n; j++)
			for(k=j+1; k<=n; k++)
				if(a[i]!=a[j] && a[j]!=a[k] && a[i]!=a[k] &&  (a[i]+a[j])>a[k])
					ans++;
	cout<<ans;
	return 0;
 } 