#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int d[2005];
int main()
{
	
	int mod=1e9+7;
		d[0]=1;
		int s;cin>>s;
		for(int i=1;i<=s;i++)
		{
			for(int j=0;j<=i-3;j++)
			{
				d[i]=(d[i]+d[j])%mod;	
			}
		}
	cout<<d[s];
	
}