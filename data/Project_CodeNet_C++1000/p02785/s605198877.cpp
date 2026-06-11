#include<bits/stdc++.h>
using namespace std;
int main()
{

		int h,n;
		cin>>n>>h;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		sort(a,a+n);
		if(h>=n)
		{
			cout<<0;
			return 0;
		}
		unsigned long long int ans=0;
		for(int i=0;i<n-h;i++)
		{
			ans+=a[i];
		}
		cout<<ans;
}