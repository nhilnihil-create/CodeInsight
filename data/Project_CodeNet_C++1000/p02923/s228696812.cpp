#include <bits/stdc++.h>
#define pi 3.14159
using namespace std;
int main()
{
	long long int i,n,c=0,ans=0,x;
	cin>>n;
	int h[n];
	for(i=0;i<n;i++)
		cin>>h[i];
	for(i=0;i<n-1;i++)
		{
			if(h[i+1]-h[i]<=0)
				{
					c++;
				}
			else
				c=0;
			ans=max(ans,c);
		}
	cout<<ans<<endl;
}