/*
h s, d't skp th si tll i's sved
 * ABC141 E
 * ABC145 D
 * ABC147 F
*/
#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
int main()
{
cout << std::setprecision(8);
cout << std::fixed;
ll n,k;
cin>>n>>k;
ll a[n];
ll pref[n+1];
pref[0]=0;
for(ll i=0;i<n;i++)
{
cin>>a[i];
pref[i+1]=pref[i]+a[i];
}
long double ans=0;
for(int i=0;i+k<=n;i++)
{
ans=max(ans,(long double)(pref[i+k]-pref[i]+k)/2);
}
cout<<ans<<endl;
}