#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long int
#define dbg(x) cout<<"( "<<#x<<" -> "<<x<<" )"<<endl;
using namespace std;
int main()
{
    IOS
    ll a,b;
    cin>>a>>b;
    map<ll,bool> mp1;
    map<ll,bool> mp2;
    if (a%2==0)
    mp1[2]=1;
    while (a%2==0)
    a/=2;
    for (ll i=3;i*i<=a;i+=2)
    {
        if (a%i==0)
        mp1[i]=1;
        while (a%i==0)
        a/=i;
    }
    if (a>2)
    mp1[a]=1;
    if (b%2==0)
    mp2[2]=1;
    while (b%2==0)
    b/=2;
    for (ll i=3;i*i<=b;i+=2)
    {
        if (b%i==0)
        mp2[i]=1;
        while (b%i==0)
        b/=i;
    }
    if (b>2)
    mp2[b]=1;
    int cnt=0;
    for (auto x: mp1)
    {
        if (mp2[x.first]==1)
        cnt++;
    }
    printf("%lld\n",(cnt+1));
    return 0;
}