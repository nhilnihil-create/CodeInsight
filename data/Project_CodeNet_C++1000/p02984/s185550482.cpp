#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   ll n;
   cin>>n;
   ll a[n],s=0,ts=0;
   for(int i=0;i<n;i++)
   {
       ll x;
       cin>>x;
       a[i]= 2*x;
       ts+=(a[i]);
       if(i%2==1)
       {
           s+= (2*a[i]);
       }
   }
   //cout<<ts<<" "<<s<<"\n";
   ll pr= ts-s;
   pr/=2;
   cout<<pr<<" ";
  for(int i=0;i<n-1;i++)
   {
      pr= a[i]-pr;
     cout<<pr<<" ";
   }

}
