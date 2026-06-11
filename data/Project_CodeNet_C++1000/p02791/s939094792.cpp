#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    long long n,a[200005],i,total=0,min[200005],mn;
    cin>>n;
    mn=10000000000;
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]<mn)
        {
            mn=a[i];
        }
        min[i]=mn;        
    }
    for(i=1;i<=n;i++)
    {
        if(a[i]<=min[i])
        {
            total++;
        }
    }
    cout<<total<<endl;
    return 0;
}