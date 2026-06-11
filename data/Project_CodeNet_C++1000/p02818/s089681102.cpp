#include<iostream>
using namespace std;
int main()
{
    long long a,b,k,d=0,m=0;
    cin>>a>>b>>k;
    if(a>=k)
    {
        d=a-k;
        cout<<d<<" "<<b<<endl;
    }
    else if(k>a)
    {
        d=k-a;
        m=b-d;
        if(d>b)
        {
            cout<<0<<" "<<0<<endl;
        }
        else if(b>=d)
        {
            cout<<0<<" "<<m<<endl;
        }
    }
    return 0;

}
