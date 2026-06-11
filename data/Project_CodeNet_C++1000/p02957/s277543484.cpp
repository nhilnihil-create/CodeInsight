#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,j,x,n,k,y;
    cin>>a>>b;
    if(a>=b)
        n=a;
    else
        n=b;
    for(int i=0;i<999999999;i++)
    {
        x=a-i;
        if(x<0)
            x=x*-1;
        y=b-i;
        if(y<0)
            y=y*-1;
        if(x==y)
        {
            cout<<i<<endl;
            return 0;

        }
    }
    cout<<"IMPOSSIBLE"<<endl;
    return 0;
}
