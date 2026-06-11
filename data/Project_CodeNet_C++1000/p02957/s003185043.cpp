#include<iostream>
#include<cstdlib>
using namespace std;
int main()
{
    int a, b, c, d,t,i,x=0;
    cin>>a>>b;
    if(a>=0&&a<=1000000000&&b>=0&&b<=1000000000)
    {
        if(a>b)
        {
            t=a;
            a=b;
            b=t;
        }
        for(i=1;i<=b;i++)
        {
            c=abs(a-i);
            d=abs(b-i);
            if(c==d)
            {
                x=i;
                break;
            }
        }
        if(x==0)
            cout<<"IMPOSSIBLE"<<endl;
        else
            cout<<x<<endl;
    }

}