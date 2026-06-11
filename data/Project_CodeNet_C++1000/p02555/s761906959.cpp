#include<bits/stdc++.h>
typedef long long ll;
#define m 1000000007
using namespace std;
/*ll mod(ll x,ll y)
{ ll ans=1;

    while(y>0)
    {
        if(y&1)
            ans=ans*x %m;
        y/=2;
        x=(x*x) %m;

    }
    return ans;
}*/
int main()
{
 /*ll a,b,c,d,m,n,res=0;
 cin>>a>>b>>c>>d;
 cout<<max(max(a*c,b*d),max(a*d,b*c))<<endl;*/

 /*ll n;
 cin>>n;
 ll ans= (mod(10,n)-(mod(9,n)*2-mod(8,n)))%m;
 //ll ans=mod(8,n);
 if(ans<0)
    ans+=m;
 cout<<ans<<endl;*/
 ll s;
 cin>>s;
 vector<ll> v(s+1);
 v[0]=1;
 for(int i=3;i<=s;i++)
 {

     for(int j=0;j<=i-3;j++)
     {
         v[i]+=v[j];
         v[i]%=m;

     }
 }
 cout<<v[s]<<endl;
return 0;
}
