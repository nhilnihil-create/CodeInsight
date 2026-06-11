#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long n,a[3000005],b[3000005],l,r;
	cin>>n;
	
	for(int i=1;i<=n;i++)
	   cin>>a[i]>>b[i];
	   
	sort(a+1,a+n+1);
	
	sort(b+1,b+n+1);
	   
	
	if(n%2==1)
	{
		l=b[(n+1)/2];
		r=a[(n+1)/2];
	}
	else
	{
		l=(b[n/2]+b[n/2+1]);
		r=(a[n/2]+a[n/2+1]);
	}
	
	cout<<l-r+1;
	  
	return 0;
	
}