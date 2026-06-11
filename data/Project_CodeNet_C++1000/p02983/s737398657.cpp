#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
int main()
{
ll l,r;
cin>>l>>r;
if(r-l>=2019)
{
cout<<0<<endl;
}
else
{
ll ans=2020;
for(ll i=l;i<=r;i++)
{
for(ll o=i+1;o<=r;o++)
{
ans=min(ans,((i%2019)*(o%2019))%2019);
}
}
cout<<ans<<endl;
}
}