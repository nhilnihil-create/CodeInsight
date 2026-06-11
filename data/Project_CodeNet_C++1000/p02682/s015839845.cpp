#include<bits/stdc++.h>
using namespace std;
int main()
{
    long int a,b,c,d,e=0;
    cin>>a>>b>>c>>d;
    if(a>=d)
    {
        e=d;
        cout<<e;
        return 0;
    }
    else
    {
        d=d-a;
        e=e+a;
        if(b>=d)
        {
            cout<<e;
            return 0;
        }
        else
        {
            d=d-b;
            e=e-d;
            cout<<e;
            return 0;
        }
    }

}
