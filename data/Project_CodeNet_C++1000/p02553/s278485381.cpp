#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
  ll a,b,c,d,x1,x2,x3,x4;
  cin>>a>>b>>c>>d;
   x1=a*c,x2=b*c;  x1=max(x1,x2);
   x3=a*d,x4=b*d;  x3=max(x3,x4);
   x1=max(x1,x3);
   cout<<x1;
return 0;
}

