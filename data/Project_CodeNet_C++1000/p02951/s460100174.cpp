#include<bits/stdc++.h>

using namespace std;

int main()
{
    int a,b,c,x,y;
    cin>>a>>b>>c;
    if(a>b)
    {
        x=a-b;
        y=c-x;
        if(y>=0)
        {
            cout<<y;
        }
        else
        {
            cout<<"0";
        }
    }
    else
    {
        cout<<c;
    }
    return 0;
}
