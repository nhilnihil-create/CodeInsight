#include<iostream>
#include<algorithm>
using namespace std;
const int N=1e6+10;
typedef long long ll;
ll gcd(ll a,ll b)
{
    return b?gcd(b,a%b):a;
}
bool check(ll x)
{
    if(x==1)    return false;
    for(ll i=2;i<=x/i;i++)
    if(x%i==0)  return false;
    return true;
}
ll a[N];
int main()
{
    ll x,y;
    cin>>x>>y;
    int cnt=0;
    ll c=min(x,y),d=max(x,y);
    for(ll i=1;i<=c/i;i++)
    {
        if(c%i==0)  
        {
            a[cnt++]=i;
            a[cnt++]=c/i;
        }
    }
    int res=0;
    for(int i=0;i<cnt;i++)
    if(check(a[i])&&d%a[i]==0) res++;
    cout<<res+1;
}