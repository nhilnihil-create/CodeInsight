#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
using namespace std;

int main()
{
       ios_base::sync_with_stdio(0);
       cin.tie(0);

       int t=1;
       //cin>>t;
       while(t--)
       {
               ll a,b;
               cin>>a>>b;
               ll n = __gcd(a,b);
               int count=0;
               while(n%2==0)
                    n/=2;
               count++;
               n = __gcd(a,b);
               for(ll i=2;i*i<=__gcd(a,b);i++)
               {
                    if(n%i==0)
                    {
                         while(n%i==0)
                         {
                              n/=i;
                         }
                         count++;
                    }

               }
               if(n>1)
                    count++;
               cout<<count;

       }
}
