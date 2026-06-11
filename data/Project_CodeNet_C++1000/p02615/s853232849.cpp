#include<bits/stdc++.h>
using namespace std;
long long a[200050];
long long ans;
int main()
{
	int n;cin>>n;
	int count1=n-1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	reverse(a+1,a+1+n);
	ans+=a[1];
	count1--;
	if(count1==0)
	{
		cout<<ans;
	}
	for(int i=2;i<=n;i++)
	{
		for(int j=1;j<=2;j++)
		{
			ans+=a[i];
			count1--;
			if(count1==0)
			{
				cout<<ans;return 0;
			}
		}
	}
	
}