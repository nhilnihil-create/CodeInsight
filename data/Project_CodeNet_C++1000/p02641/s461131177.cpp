#include<bits/stdc++.h>
using namespace std;
typedef  long long ll;
#define pb push_back
#define eb emplace_back
const  int MAX=1000000;

int main()
{
   ll t;

   t=1;

   while(t--)
   {


       ll x,n;

       cin>>x>>n;

       map<ll,ll>m;

       while(n--)
       {
           ll a;
           cin>>a;
           m[a]=1;
       }
       ll i=x-1;
       ll j=x+1;
       while(1)
       {
           if(m[x]==0)
           {
               cout<<x<<endl;
               break;
           }
           if(m[i]==0)
           {
               cout<<i<<endl;
               break;
           }
           if(m[j]==0)
           {
               cout<<j<<endl;
               break;
           }
           i--;
           j++;

       }







   }

    }









