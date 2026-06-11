#include<bits/stdc++.h>
#define ft(i,l,r) for(register int i=l;i<=r;i++)
#define fd(i,r,l) for(register int i=r;i>=l;i--)
using namespace std;
int n,x,mx,bo;
int main()
{
	cin>>n;
	ft(i,1,n)
	{
		scanf("%d",&x);
		mx=max(mx,x);
		if(mx-x>=2) bo=1;
	}
	if(bo==1) cout<<"No";
	else cout<<"Yes";
	cout<<endl;
	return 0;
}