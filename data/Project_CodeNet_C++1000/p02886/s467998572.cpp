#include<iostream>
using namespace std;
int main()
{
    int n,s=0,t=0,x;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];

        t=t+(a[i]*a[i]);
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
           s=s+(a[i]*a[j]);
        }
    }
     x=(s-t)/2;
    cout<<x<<endl;
    return 0;
}
