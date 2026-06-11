#include<bits/stdc++.h>
#define ios ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
using namespace std;
int a[16],b[16],c[16];
int main()
{
	ios;
	int n;
	cin>>n;
	for(int i=1;i<=n;++i)cin>>a[i];
	for(int i=1;i<=n;++i)cin>>b[i];
	for(int i=1;i<=n;++i)c[i]=i;
	int num1=0,num2=0;
	int flag1=0,flag2=0,t=0;
	do
	{
		t++;
		if(!flag1)
		{
			int flag=1;
			for(int i=1;i<=n;++i)
			{
				if(c[i]!=a[i]){flag=0;break;}
			}
			if(flag)
			{
				flag1=1;
				num1=t;
			}
		}
		if(!flag2)
		{
			int flag=1;
			for(int i=1;i<=n;++i)
			{
				if(c[i]!=b[i]){flag=0;break;}
			}
			if(flag)
			{
				flag2=1;
				num2=t;
			}
		}
	}while(next_permutation(c+1,c+1+n));
	cout<<abs(num1-num2)<<'\n';
}