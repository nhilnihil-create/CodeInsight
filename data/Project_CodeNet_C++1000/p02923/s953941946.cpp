#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>>n;
   ll a[n];
   for(int i=0;i<n;i++)
   {
       cin>>a[i];
   }
   ll c=0,ans=0;
   for(int i=0;i<n-1;i++)
   {
       if(a[i+1]>a[i])
       {
           ans= max(ans,c);
           c=0;
       }
       else
        c++;
   }
   ans= max(ans,c);
   cout<<ans;
}
