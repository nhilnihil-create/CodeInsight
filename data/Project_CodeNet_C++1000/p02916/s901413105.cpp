#include <iostream>
using namespace std;

int main()
{
    int n,pts=0;
    cin>>n;
    int a[n],b[n],c[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>b[i];
        pts=pts+b[i];
    }
    for(int i=0;i<n-1;i++)
    {
        cin>>c[i];
    }
    for(int i=0;i<n;i++)
    {
        if(a[i+1]==a[i]+1)
        pts=pts+c[a[i]-1];
    }
    cout<<pts;
    
    return 0;
}