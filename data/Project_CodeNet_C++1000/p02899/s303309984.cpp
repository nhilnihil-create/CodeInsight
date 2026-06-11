#include<iostream>
using namespace std;
int main()
{
    int i,n,k,c=0,l;
    cin>>n;
    int a[n+1];
    for(i=1;i<=n;i++)
    {
        cin>>l;
        a[l]=i;
    }
    for(i=1;i<=n;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}
