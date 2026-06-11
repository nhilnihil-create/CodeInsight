#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll>pll;
const int N=1e6;
ll v[N+10];
ll pos[N];
int main()
{

   ll a,b,c,d,gcd=0,lcm=0,ans1=0,ans=0,sum=0,bug=0,ans2=0,ans3=0;

   cin>>a>>b>>c>>d;

   gcd=__gcd(c,d);

   lcm=(c*d)/gcd;

   ans=b/c;

   ans1=b/d;

   sum=ans+ans1;

   bug=b/lcm;

   sum-=bug;

   sum=b-sum;

   ans3=sum;

    a--;

    ans=a/c;

   ans1=a/d;

   sum=ans+ans1;

   bug=a/lcm;

   sum-=bug;

   sum=a-sum;

   cout<<abs(sum-ans3)<<endl;








}



