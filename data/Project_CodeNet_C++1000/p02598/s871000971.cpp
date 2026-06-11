//tanzim bin nasir
#include<bits/stdc++.h>
typedef long long ll;
#define ff first
#define ss second
using namespace std;
void fast()
{
ios::sync_with_stdio(false);
cin.tie(NULL); cout.tie(NULL);
}
int gcd(int a,int b)
{
    if(b==0)
    return a;
    else
    gcd(b,a%b);
}
ll lcd(ll a,ll b)
{
    return (a*b)/gcd(a,b);
}
ll a[200005],n,k;
bool check(ll x)
{
    ll temp=0;
    for(int i=0;i<n;i++)
    {
        temp+=(a[i]-1)/x;
    }
    if(temp>k)
    return false;
    return true;
}
int main()
{
     ll l=1,r=0;
     cin>>n>>k;
     for(int i=0;i<n;i++)
     {
        cin>>a[i];
        r=max(r,a[i]);
     }
     ll ans;
     while(l<=r)
     {
         ll mid=(l+r)/2;
         if(check(mid))
         {
             ans=mid;
             r=mid-1;
         }
         else
         l=mid+1;
     }
     cout<<ans<<endl;
}
