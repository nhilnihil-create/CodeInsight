/*Rabbi Zidni Ilma*/
 
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define scl(n) scanf("%lld",&n)
#define scll(n,m) scanf("%lld %lld",&n,&m)
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define mod 1000000007
#define read freopen("input.txt","r",stdin)
#define write freopen("output.txt","w",stdout)

ll pow(ll b,ll p)
{
	ll res=1;
	for(ll i=1;i<=p;i++)
	res=((res%mod)*(b%mod))%mod;
	
	return res%mod;
}
 
int main()
{
   ll n,i,ans;
   scl(n);
   ans=pow(10ll,n)-2*pow(9ll,n)+pow(8ll,n);
   while(ans<0)
   ans=(ans+mod)%mod;
   printf("%lld\n",ans);
}