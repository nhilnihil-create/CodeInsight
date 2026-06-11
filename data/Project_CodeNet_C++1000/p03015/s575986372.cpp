#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll p=1000000007;
ll bin(ll x,ll po)
{
    ll ans=1;
    if(po==0)
        return ans;
    if(po%2==1)
    {
        ans=ans*x%p;
        po--;
    }
    ll p1=bin(x,po/2);
    ans=ans*p1%p;
    ans=ans*p1%p;
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin>>s;
    ll n=s.length();
    ll ans=0;
    ll cur=1;
    for(ll i=0;i<s.length();i++)
    {
        if(s[i]=='1')
        {
            ans=(ans+cur*(bin(3,n-1-i))%p)%p;
            cur=cur*2%p;
        }
    }
    ans=(ans+cur)%p;
    cout<<ans;
}