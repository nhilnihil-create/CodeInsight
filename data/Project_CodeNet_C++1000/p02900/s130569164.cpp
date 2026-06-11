#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int xx;
const ll N=1e7+7;
ll A[N];
vector<ll> v;
void sieve()
{
    for(ll i=3; i<=2000; i+=2)
    {
        for(ll j=i*i; j<=4000000; j+=i)
            A[j]=1;
    }
    v.push_back(2);
    for(ll i=3; i<=4000000; i+=2)
        if(A[i]==0)
            v.push_back(i);
}

int main()
{
    sieve();
   ll a,b,cnt=0;
   cin>>a>>b;
   ll d=__gcd(max(a,b),min(a,b));
   for(ll i=0;v[i]<=sqrt(d);i++)
   {
       if(d%v[i]==0)
       {
           while(d%v[i]==0)
             {
                 d/=v[i];
             }
           cnt++;
       }
   }
   if(d!=1)
   {
       cnt++;
   }
   cout<<cnt+1<<endl;
return 0;
}









