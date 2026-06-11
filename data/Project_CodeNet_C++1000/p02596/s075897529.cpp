#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll p[1000005];
int main()
{
   ll a,b,c,d;
   cin>>a;
   ll k=7;
   ll ans=1;
   while(1)
   {


       if(k<a)
       {
           ans++;
           k*=10;
           k+=7;
       }
       else
       {
           k=k%a;
           if(k==0)
           {
               cout<<ans<<endl;
               return 0;
           }
           if(p[k]==1&&k!=0)
           {
               cout<<"-1"<<endl;
               return 0;
           }
               p[k]=1;

       }


   }

    return 0;
}
