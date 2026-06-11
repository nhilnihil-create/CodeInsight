#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long n;
	cin>>n;
	long long x=100;
	long long ans=0;
	while(x<n)
	{
		x+=x/100;
		ans++;
	}
	cout<<ans<<endl;
 } 