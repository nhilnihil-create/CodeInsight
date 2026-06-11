#include<bits/stdc++.h>
using namespace std;
typedef  long long ll;
#define pb push_back
#define eb emplace_back
const  int MAX=1000000;
ll m[MAX+10];

int main()
{
     ll n;

     cin>>n;

     ll a[n+2];

     for(ll i=0;i<n;i++)cin>>a[i];

     sort(a,a+n);

     for(ll i=0;i<n;i++)
     {
         if(i>0 && a[i]==a[i-1])
         {
             m[a[i]]++;
             continue;
         }

         for(ll j=a[i];j<=MAX;j+=a[i])
         {
             m[j]++;
         }
     }

     ll cnt=0;

     for(ll i=0;i<n;i++)
     {
         if(m[a[i]]==1)cnt++;
     }

     cout<<cnt<<endl;

}


