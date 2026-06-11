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
     ll n,k;

     cin>>n>>k;


     ll ara[n+1];

     for(ll i=0;i<n;i++)
     {
         cin>>ara[i];
     }


     sort(ara,ara+n);

      ll sum=0;


      for(ll i=0;i<k;i++)sum+=ara[i];

      cout<<sum<<endl;




   }

    }









