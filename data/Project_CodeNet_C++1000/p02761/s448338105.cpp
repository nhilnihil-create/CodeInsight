#include<bits/stdc++.h>
using namespace std;
#define ll long long int
string s;
	



int main()
{
 ll n,m;
 cin>>n>>m;
 
 ll s,c,ans[n];
 
 for(ll i=0;i<n;i++)ans[i]=-1;
 for(ll i=0;i<m;i++)
 {
 	cin>>s>>c;
 	
 	if((ans[s-1]==-1||ans[s-1]==c  ))
 	ans[s-1]=c;
 	else
 	return cout<<-1,0;
 }
 if(ans[0]==0&&n!=1)return cout<<-1,0;
 
 for(ll i=1;i<n;i++)
 {
 	if(ans[i]==-1)ans[i]=0;
 }

if(ans[0]==-1&&n>1)ans[0]=1;
else if(ans[0]==-1)ans[0]=0;

for(ll i=0;i<n;i++)cout<<ans[i];
}


