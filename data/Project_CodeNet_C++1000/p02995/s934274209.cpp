#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
//typedef pair<int,int> pii;
lli gcd(lli a,lli b)
{
    if(a%b==0) return b;
    return gcd(b,a%b);
}
int main()
{
     lli a,b,c,d;
     cin>>a>>b>>c>>d;
     lli Dc=((b/c)-(a+c-1)/c)+1; //cout<<Dc<<endl;
     lli Dd=((b/d)-(a+d-1)/d)+1;   //cout<<Dd<<endl;
     lli m=gcd(c,d);
     lli lcm=c*(d/m);
     lli Dcd=((b/lcm)-(a+lcm-1)/lcm)+1; //cout<<Dcd<<endl;
     lli ans=b-a+1-(Dc+Dd-Dcd);
     cout<<ans;

}
