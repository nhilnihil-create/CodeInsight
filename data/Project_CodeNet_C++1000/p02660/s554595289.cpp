/**
 *    author:  Daredevil666
 *    institution: IIT Patna
**/
#define _USE_MATH_DEFINES
#include<bits/stdc++.h>
#define nl cout<<"\n";
#define ll unsigned long long int
#define IOS  ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
const ll mod=1e18;
int main()
{
IOS
ll n;
cin>>n;
ll p=0;
for(ll i=2;i<=sqrt(n);i++)
{
    ll cnt=0;
    while(n%i==0)
    {
        cnt++;
        n/=i;
    }
    ll c=1+8*cnt;
    c=sqrt(c);
    c-=1;
    c/=2;
    if(c>0)
        p+=c;
}
if(n>1)
    p++;
cout<<p;
return 0;
}
