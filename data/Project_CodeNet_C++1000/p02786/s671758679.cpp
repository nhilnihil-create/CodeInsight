#include<bits/stdc++.h>
using namespace std;
long long n;
long long x;
long long ans=1;
int main()
{
	cin>>x;
	while(x)
	{
		x/=2;
		++n;
	}
	for(int i=1;i<=n;++i)
	   ans*=2;
	ans--;
	cout<<ans<<endl;
	return 0;
 } 