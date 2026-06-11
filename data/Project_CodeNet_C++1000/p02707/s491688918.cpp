#include<bits/stdc++.h>
#define ll long long
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;
int main()
{
    fast_io
    ll i,n,x;
    cin>>n;
    ll a[n]={0};
   for(i=0;i<n-1;i++)
   {
       cin>>x;
       a[x-1]++;
   }
   for(i=0;i<n;i++)
   {
       cout<<a[i]<<endl;
   }
    return 0;
}


