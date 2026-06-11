#include<bits/stdc++.h>
using namespace std;
int A,B,a[100100],b[100100],M;
int main()
{
	cin>>A>>B>>M;
	int mna=10000000,mnb=10000000;
	for(int i=1;i<=A;i++) scanf("%d",a+i),mna=min(mna,a[i]);
	for(int i=1;i<=B;i++) scanf("%d",b+i),mnb=min(mnb,b[i]);
	int ans=mna+mnb;
	for(int i=1;i<=M;i++)
	{
		int x,y,z;scanf("%d%d%d",&x,&y,&z);
		ans=min(ans,a[x]+b[y]-z);
	}
	cout<<ans<<endl;
}