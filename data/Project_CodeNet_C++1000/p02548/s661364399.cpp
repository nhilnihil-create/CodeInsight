#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		int j=n/i;
		ans+=j;
		if(i*j==n)
			ans--;
	}
	cout<<ans;
	return 0;
}