#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
int main()
{
ll a,b,c,d;
cin>>a>>b>>c>>d;
ll cnt=a/c,cnt2=a/d;
ll r=c*d/(__gcd(c,d));
ll k=a/r;
ll f=cnt+cnt2-k;
 cnt=b/c,cnt2=b/d;
 r=c*d/(__gcd(c,d));
k=b/r;
ll f2=cnt+cnt2-k;
ll h=f2-f+(a%c==0 || a%d==0);
cout<<b-a+1-h<<endl;
}