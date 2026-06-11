#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll p[2000005];
ll a;
bool check(ll mid,ll k)
{
    ll ans=0;
    if(mid==0)
    {
        for(ll i=0;i<a;i++)
            ans+=p[i]*3;
    }
    else{
    for(ll i=0;i<a;i++)
    {
long double m =(p[i]*1.0/(1.0*mid));
      ans+=ceil(m)-1;
    }
    }

    if(ans<=k)
        return true;
    else
        return false;
}
int main()
{
   ll b,c,d,k=0;
   cin>>a>>b;
   for(ll i=0;i<a;i++){
    cin>>p[i];
    k=max(k,p[i]);
   }
    ll l = 1, r =k+100, mid;
    while(l < r)
      {
        mid = (l + r) >> 1;
        if(check(mid,b)) r = mid;
        else l = mid + 1;
      }

      cout<<l<<endl;

    return 0;
}
