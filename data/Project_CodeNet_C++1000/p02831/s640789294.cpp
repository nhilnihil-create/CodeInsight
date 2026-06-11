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
ll a,b;
cin>>a>>b;
ll ans=a*b;
ll g=__gcd(a,b);
cout<<ans/g<<endl;
}