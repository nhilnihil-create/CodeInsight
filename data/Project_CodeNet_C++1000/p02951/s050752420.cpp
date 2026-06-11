#include<iostream>
using namespace std;
int main()
{
    long long int a,b,c,d,e;
    cin>>a>>b>>c;
    if(a>b)
        d=a-b;
    e=c-d;
    if(e>=0)
        cout<<e;
    else
        cout<<0;
    return 0;
}
