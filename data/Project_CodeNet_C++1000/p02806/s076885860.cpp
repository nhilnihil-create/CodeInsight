#include<bits/stdc++.h>
using namespace std;
int n,t[100],ans,che;
string a[100],p;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		cin>>a[i]>>t[i];
	cin>>p;
	for(int i=1;i<=n;i++)
	{
		if(che==1)
			ans+=t[i];
		if(a[i]==p)
			che=1;
	}
	cout<<ans;
	return 0;
}
