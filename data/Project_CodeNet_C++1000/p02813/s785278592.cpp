#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int a[10],p[10],q[10];
int main()
{
	int l,r,n;
	int ans=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		a[i]=i;
	}
	for(int i=1;i<=n;i++) cin>>p[i];
	for(int i=1;i<=n;i++) cin>>q[i];
	do{
		ans++;
		int flag=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]!=p[i]) flag=1;
		}
		if(!flag) l=ans;
		flag=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]!=q[i]) flag=1;
		}
		if(!flag) r=ans;
	}while(next_permutation(a+1,a+1+n));
	cout<<abs(r-l)<<"\n";
	return 0;
}