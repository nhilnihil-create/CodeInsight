#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long a,b,c,d;
    cin>>a>>b>>c>>d;
    long long e[4];
    e[0]=a*c;
    e[1]=a*d;
    e[2]=b*c;
    e[3]=b*d;
    a=max(e[0],max(e[1],max(e[2],e[3])));
    cout<<a;

}