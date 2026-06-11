#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main()
{
ll a,b,c;
cin>>a>>b>>c;
ll ans=b*((a)/(b+c)),d;
d=(a%(c+b));
if(d<=b)ans+=d;
else ans+=b;
cout<<ans;
}