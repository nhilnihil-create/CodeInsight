#include<iostream>
using namespace std;
int main()
{
    int i,a,b,n,m,l=0;
    cin>>a>>b;
    for(i=1;i<=2000;i++)
    {
        m=(i*(0.08));
        n=(i*(0.1));
        if(m==a&&n==b)
        {
            l++;
            cout<<i<<endl;
            break;
        }
    }
    if(l==0)
    {
        cout<<"-1"<<endl;
    }
    return 0;
}