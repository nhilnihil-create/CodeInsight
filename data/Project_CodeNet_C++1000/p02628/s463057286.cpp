#include<bits/stdc++.h>
using namespace std;


int main()
{
	int n,k;  cin>>n>>k;
	int p[1001];	
	int i;
	for( i=0;i<n;i++)  cin>>p[i];
	sort(p,p+n);
	
	int ans=0;
	
	for(i=0;i<k;i++) ans+=p[i];
	
	
	cout<<ans<<endl;
}

