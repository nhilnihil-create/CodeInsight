#include<iostream>
using namespace std;
int main()
{
    long long n,m,a[300],i,s,total=0,k=0;
    cin>>n>>m;
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
        total+=a[i];
    }
    for(i=1;i<=n;i++)
    {
        if((a[i]*4*m)>=total)
        {
            k++;
        }
    }
    if(k>=m)
    {
        cout<<"Yes"<<endl;
    }
    else
    {
        cout<<"No"<<endl;
    }
    return 0;
}