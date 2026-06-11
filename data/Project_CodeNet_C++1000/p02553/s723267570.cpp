#include<iostream>
#define ll long long
using namespace std;
int main()
{
ll   a,b,c,d;
   cin>>a>>b>>c>>d;
   ll k1=max(a,b)*max(c,d) ;
ll k2=max(a,b)*min(c,d);
ll k3=min(a,b)*max(c,d);
ll k4=min(a,b)*min(c,d);
ll res=max(max(k1,k2),max(k3,k4));

cout<<res<<'\n';

return 0;
}