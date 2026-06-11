#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a,b,d;
    cin>>a>>b;
    if((a>0 && a<10) && (b>0 && b<10))
    {
        d=a*b;
    }
    else
    {
        d=-1;
    }
    cout<<d<<endl;
    return 0;
}
