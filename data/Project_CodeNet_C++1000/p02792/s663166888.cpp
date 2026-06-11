#include<bits/stdc++.h>
using namespace std;
long long mp[10][10];
void f(int x)
{
	int mo=x%10;
	int shou;
	if(x<10)
	{
		shou=x;
	}
	else if(x<100)
	{
		shou=x/10;
	}
	else if(x<1000)
	{
		shou=x/100;
	}
	else if(x<10000)
	{
		shou=x/1000;
	}
	else if(x<100000)
	{
		shou=x/10000;
	}
	else if(x<1000000)
	{
		shou=x/100000;
	}
	if(mo!=0&&shou!=0)
	{
		mp[shou][mo]++;
	}
}
long long ans;
int main()
{
	int n;cin>>n;
	for(int i=1;i<=n;i++)
	{
		f(i);
	}
	for(int i=1;i<=9;i++)
	{
		for(int j=i;j<=9;j++)
		{
			if(i==j&&mp[i][j])
			{
				ans+=mp[i][j]*mp[i][j];
			}
			else if(i!=j&&mp[i][j]&&mp[j][i])
			{
				ans=ans+mp[i][j]*mp[j][i]*2;
			}
		}
	}
	cout<<ans<<endl;
}