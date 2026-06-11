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
	ull t;
	t=1;
	while(t--)
	{
		ll n,i;
		cin>>n;
		
		ll a[n],b[n];
		
		for(i=0;i<n;i++)
		{
			cin>>a[i]>>b[i];
		}
		
		for(i=0;i<=n-3;i++)
		{
			if(a[i]==b[i] && a[i+1]==b[i+1] && a[i+2]==b[i+2])
			{
				cout<<"Yes";
				return 0;	
			}	
		}
		cout<<"No";
	}
}