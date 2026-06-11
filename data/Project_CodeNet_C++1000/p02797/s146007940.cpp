//author CN.TTDragon
#include<bits/stdc++.h>
typedef long long ll;
const ll mod=1e9+7;
const ll maxn=1e5+7;
const double pi=acos(-1);
using namespace std;
int a[maxn];
int main()
{
    ios::sync_with_stdio(false);
    int n,m,sum;
    cin>>n>>m>>sum;
    for(int i=0;i<m;i++)
    {
    	if(i%2==0)
    	{
    		a[i/2]=sum;
		}
		else
		{
			a[n-1-i/2]=sum;
		}
	}
	
	if(sum==1e9)
	{
		for(int i=0;i<n;i++)
		{
			if(a[i]==0)
			{
				a[i]=sum-1;
			}
		}
	}
	else
	{
		for(int i=0;i<n;i++)
		{
			if(a[i]==0)
			{
				a[i]=sum+1;
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
 	return 0;
}
