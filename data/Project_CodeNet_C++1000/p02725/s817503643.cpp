#include<bits/stdc++.h>
using namespace std;
int a[200010];
int l[200010];
int main()
{
    int n,k;
    cin>>k>>n;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    sort(a+1,a+1+n);
    for(int i=1;i<n;i++)  l[i]=a[i+1]-a[i];
	l[n]=k-a[n]+a[1];
	int maxx=-1;
	for(int i=1;i<=n;i++)
	{
		if(l[i]>maxx)   maxx=l[i];
	}
	cout<<k-maxx<<endl;
    return 0;
}