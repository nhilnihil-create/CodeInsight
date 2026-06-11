#include<bits/stdc++.h>
#define mx 10000010
using namespace std;
int main()
{
	long long int i,n,j,sum=0;
	vector<int> div(mx+1);
	cin>>n;
	for(i=1;i<=n;i++)
	{
		for(j=i;j<=n;j+=i)
		{
			div[j]++;
		}
	}
	for(i=1;i<=n;i++)
	{
		sum+=div[i]*i;
	}
	cout<<sum<<endl;
	return 0;
	
}