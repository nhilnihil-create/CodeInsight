#include<iostream>
using namespace std;
int main()
{
    long long n,m,p,i;
    cin>>n>>m;
    p=min(n,m);
    if(p==n)
    {
        for(i=1;i<=m;i++)
        {
            cout<<n;
        }
        cout<<endl;
    }
    else
    {
        for(i=1;i<=n;i++)
        {
            cout<<m;
        }
        cout<<endl;
    }
    return 0;
}