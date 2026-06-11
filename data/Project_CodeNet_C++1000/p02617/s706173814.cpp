#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll bg = 20000001;
#define ff(i,n) for(i=0;i<n;i++) 
int main()
{
  		ll i,n,u,v;
		cin>>n;
		ll ans = (n*(n+1)*(n+2))/6;
		ff(i,n-1)
		{
			cin>>u>>v;
			ans-=((min(u,v))*(n-max(u,v)+1));	
		}    
		cout<<ans;
		return 0;
} 