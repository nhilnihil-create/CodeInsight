#include<bits/stdc++.h>
using  namespace std;
int main()
{
 long long a,b,c,d,p,q,r,s,x,y;
 cin>>a>>b>>c>>d;
    p=a*c;
    q=a*d;
    r=b*c;
    s=b*d;
    x=max(p,q);
    y=max(r,s);
cout<<max(x,y);
    return 0;
}