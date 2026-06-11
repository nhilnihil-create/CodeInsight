#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007
int main()
{
ll a,b,c,d,e,f,g,h,t,tt,ans;
cin>>a>>b>>c>>d;
e=a*c;
f=a*d;
g=b*c;
h=b*d;
ans=max(max(e,f),max(g,h));
cout<<ans<<endl;
}