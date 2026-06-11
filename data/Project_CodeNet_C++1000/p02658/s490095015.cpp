#include<bits/stdc++.h>
using namespace std;
long long x;
__int128 ans=1; 
long long a[100005];
void print(__int128 x)
{
	if (!x) return ;
	if (x < 0) putchar('-'),x = -x;
	print(x / 10);
	putchar(x % 10 + '0');
}
int main()
{
	int flag=1;
	int n;cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==0)
		{
			flag=0;
		}
	}
	if(!flag)
	{
		cout<<"0";return 0;
	}
	else
	{
		int flag1=1;
		for(int i=1;i<=n;i++)
		{
			ans*=a[i];
			if(ans>1000000000000000000LL)
			{
				flag1=0;
			}
		}
		if(!flag1)
		{
			cout<<"-1";return 0;
		}
		else
		{
			print(ans);
		}
	}
}