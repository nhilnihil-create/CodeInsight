#include<bits/stdc++.h>
using namespace std;
int main()
{
	unsigned long long int n;
	cin>>n;
	unsigned long long int ans=0;
	if(n%2==1)
	{
		cout<<0;
		return 0;
	}
	n=n/2;
	while(n>0)
	{
		ans+=n/5;
		n=n/5;
	}
	cout<<ans;
}
