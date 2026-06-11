#include <iostream>

using namespace std;

int main()
{
    int a,b,c,maxn;
    cin>>a>>b>>c;
    maxn=max(a, b);
    maxn=max(maxn, c);
    if(maxn==a)
    {
        cout<<b+c;
    }
    else if(maxn==b)
    {
        cout<<a+c;
    }
    else
    {
        cout<<a+b;
    }
}