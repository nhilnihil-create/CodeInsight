#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
ll n,c=0; cin>>n;
ll a[n];
ll mn=INT_MAX;
for(ll i=0;i<n;i++)
{
    cin>>a[i];
    mn=min(mn,a[i]);
   // cout<<mn<<endl;
    if(mn==a[i])
    {
       c++;
    }
}
cout<<c<<endl;
}

