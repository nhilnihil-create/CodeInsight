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
		ll a,b,c,d;
		cin>>a>>b>>c>>d;
		ll A[2]={a,b},B[2]={c,d};
		
		ll i,j,ans=-1*(1e18);
		
		for(i=0;i<2;i++)
		{
			for(j=0;j<2;j++)
			{
				ll p=A[i]*B[j];
				ans=max(ans,p);
			}
		}
		
		cout<<ans;	
	}
}