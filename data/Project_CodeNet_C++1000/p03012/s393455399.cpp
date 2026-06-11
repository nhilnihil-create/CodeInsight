#include <bits/stdc++.h>
#define pi 3.14159
using namespace std;

int main()
 {
 	int n,i,x,d,s=0,s1=0;
 	int ans=INT_MAX;
 	cin>>n;
 	int a[n],b[n],c[n];
 	for(i=0;i<n;i++)
 		cin>>a[i];
 		for(i=0;i<n;i++)
 		{
 			s=s+a[i];
 			b[i]=s;
		 }
		 for(i=n-1;i>=0;i--)
		 {
		 	s1=s1+a[i];
		 	c[i]=s1;
		 }
		for(i=0;i<n-1;i++)
		{
			ans=min(ans,abs(b[i]-c[i+1]));
		}
		cout<<ans<<endl;
 	}