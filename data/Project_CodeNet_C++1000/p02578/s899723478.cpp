#include<bits/stdc++.h>
using namespace std;
long long int a[100000000],n,m=0;
int main()
{
	cin>>n;
	cin>>a[1];
	for (int i=2;i<=n;i++)
     {
	   cin>>a[i];
	   if (a[i]<a[i-1]) 
	   {
	   	m=a[i-1]-a[i]+m;
        a[i]=a[i-1];
	   }
	 }
     cout<<m;
return 0;
 } 