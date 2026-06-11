#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long int a,b,c,d,e;
    cin>>a>>b>>c;
    d=4*a*b;
    e=(c-a-b)*(c-a-b);
    if(a+b>c)
    {
        cout<<"No"<<endl;
    }
    else
    {
        if(d<e)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
}
