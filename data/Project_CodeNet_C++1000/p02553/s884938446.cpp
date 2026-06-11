#include<bits/stdc++.h>
using namespace std;
int main()
{
   long long int a,b,c,d,p[4];
   cin>>a>>b>>c>>d;
   p[0]=a*c;
   p[1]=a*d;
   p[2]=b*c;
   p[3]=b*d;
   long long int m,n,ma;
   m=max(p[0],p[1]);
   n=max(p[2],p[3]);
   ma=max(m,n);
   cout<<ma<<endl;
}
