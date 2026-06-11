#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long n,j,sum=0;
	cin>>n;
	for(long long i=1;i<=n-1;i++)
	{
		if(n%i==0)
		sum+=n/i-1;
		else
		sum+=n/i;
	}
	cout<<sum<<endl;
	return 0;
}