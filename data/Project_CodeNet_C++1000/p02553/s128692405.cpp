#include <bits/stdc++.h>
using namespace std;
long long a,b,c,d,s,t,r,n,m,l,k,j;
int main(){
    cin>>a>>b>>c>>d;
    s=a*c;
    t=b*d;
    r=a*d;
    n=b*c;
    m=max(s,t);
    k=max(m,r);
    j=max(k,n);
    cout<<j;


return 0;}


