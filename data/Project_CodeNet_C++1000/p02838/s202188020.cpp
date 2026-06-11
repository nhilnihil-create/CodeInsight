#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pi 3.141592653589793238
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MOD 1000000007
int main()
{
        fast;
       ll n;
       cin>>n;
       ll arr[n];
       for(int i=0;i<n;i++)
    	cin>>arr[i];
	   ll b[64]={0},ans=0,m=1e9+7,p=1;
		for(ll i=0;i<64;i++)
			for(ll j:arr) 
				if(j & (1ll<<i))
					b[i]++;
		 for(ll i=0;i<64;i++)
	    {
	        p=pow(2,i);
	        p%=MOD;
	        ans+=((((n-b[i])*b[i])%MOD)*p%MOD);
	        ans%=MOD;
		}
		cout<<ans;
        return 0;
}
