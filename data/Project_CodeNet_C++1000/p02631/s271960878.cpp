#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
   ll n;
   cin>>n;
   ll a[n];
   ll xorsum=0;
   for(ll i=0;i<n;i++){
       cin>>a[i];
       xorsum^=a[i];
   }
   ll num;
   for(ll i=0;i<n;i++){
       num=xorsum^a[i];
       cout<<num<<" ";
   }
}