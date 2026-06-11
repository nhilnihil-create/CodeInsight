#include<bits/stdc++.h>
# define ll long long
# define pb push_back
# define mod 1000000007
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
    	cin>>a[i];
	}
	int c[100005]={0};
	c[0]=3;
	ll ans=1;
	for(int i=0;i<n;i++)
	{
		ans=ans*c[a[i]]%mod;
		c[a[i]]--;
		c[a[i]+1]++;	
	}
	cout<<ans;
	return 0;
}