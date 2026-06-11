#include<iostream>
using namespace std;
long long mod(long long a)
{
    if(a<0)
        return a*-1;
    else
        return a;
}
int main()
{
    long long a,b,c,m1,m2;
    cin>>a>>b;
    c=(a+b)/2;
    m1=mod(a-c);
    m2=mod(b-c);
    if(m1==m2)
        cout<<c;
    else
        cout<<"IMPOSSIBLE";
    return 0;
}

