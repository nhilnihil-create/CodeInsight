#include<bits/stdc++.h>
using namespace std;
typedef long long ll;  
#define pb push_back
#define F first
#define S second
#define ppp pair<ll,pair<ll,ll>>
#define pp pair<ll,ll>
#define all(x) (x).begin(),(x).end()
#define pi 3.14159265358
#define MOD 998244353
int main()
{
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
   	 ll n,i,j,k;

   	 cin>>n;

   	 vector<ll> v;
   	 for(i=2;i<=sqrt(n);i++)
   	 {	
   	 	ll occ=0;
   	 	while(n%i==0)
   	 	{
   	 		n=n/i;
   	 		occ++;
   	 	}
   	 	if(occ!=0)
   	 		v.pb(occ);
   	 }

   	 if(n!=1)
   	 	v.pb(1);

   	 ll ans=0;
   	 for(i=0;i<v.size();i++)
   	 {
   	 	ll sum=0;
   	 	for(j=1; ;j++)
   	 	{
   	 		if(sum+j>v[i])
   	 			break;
   	 		sum+=j;
   	 	}

   	 	ans+=j-1;
   	 	//cout<<v[i]<<" "<<j<<endl;
   	 }

   	 cout<<ans<<endl;



}

