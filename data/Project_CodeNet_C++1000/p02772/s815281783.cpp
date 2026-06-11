#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
   ll n,i;
   cin>>n;
   ll a[n];
   int flag=0;
   for(i=0;i<n;i++)
   {
       cin>>a[i];
   }
    for(i=0;i<n;i++)
   {
       if(a[i]%2==0)
       {
           if(a[i]%3==0 || a[i]%5==0)
           {
               continue;
           }
           else
           {
               flag=1;
               break;
           }
       }
   }
   if(flag) cout<<"DENIED";
   else cout<<"APPROVED";
    return 0;
}