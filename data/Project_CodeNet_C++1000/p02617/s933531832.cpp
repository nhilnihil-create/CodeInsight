#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
  		ll i,n,u,v,ans;
		cin>>n;
		ans = (n*(n+1)*(n+2))/6;
		for(i=0;i<n-1;i++) 
		{
			cin>>u>>v;
			ans-=((min(u,v))*(n-max(u,v)+1));	
		}    
		cout<<ans;
		return 0;
} 