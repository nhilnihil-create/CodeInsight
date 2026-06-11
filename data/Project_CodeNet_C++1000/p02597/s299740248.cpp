#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
#define ull unsigned long long int 
#define pb push_back
#define xx first
#define yy second

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll t;
	t=1;
	while(t--)
	{
		ll n;
		cin>>n;
		string s;
		cin>>s;
		ll i,ans=0;
		ll cnt=0;
		for(i=0;i<n;i++)
		{
		    if(s[i]=='R')
		        cnt++;
		}
		
		for(i=0;i<cnt;i++)
		{
		    if(s[i]!='R')
		        ans++;
		}
		
		cout<<ans;
	}
}