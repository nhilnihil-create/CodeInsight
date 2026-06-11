#include<bits/stdc++.h>
using namespace std;
int main()
{
	int i,n,m,ans=0,x;
	cin>>n>>m;
	for(i=1;i<=m;i++)
	{
		cin>>x;
		ans+=x;
	}
	if(ans>n)cout<<"-1";
	else cout<<n-ans;
}
