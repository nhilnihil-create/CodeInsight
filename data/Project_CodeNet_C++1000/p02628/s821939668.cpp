#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int main()
{
    ll n,i,j,k,s=0,c=1,x=1,t;
   cin>>n>>k;
   ll a[n+1];
   for(i=0;i<n;i++)
          cin>>a[i];
   sort(a,a+n);
   for(i=0;i<k;i++)
          s+=a[i];
   cout<<s;
}
