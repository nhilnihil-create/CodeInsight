#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long int n, c=0;
    cin>>n;
    int a[n+1], b[n];
    for(int i=0; i<=n; i++)
    {
        cin>>a[i];
    }
    for(int i=0; i<n; i++)
    {
        cin>>b[i];
    }
    for(int i=n-1; i>=0; i--)
    {
        if(b[i]>=a[i+1])
        {
            c+=a[i+1];
            b[i] -= a[i+1];
            a[i+1]=0;
        }
        else
        {
            c+=b[i];
            a[i+1]-= b[i];
            b[i]=0;
        }
        if(b[i]>=a[i])
        {
            c+=a[i];
            a[i]=0;
        }
        else
        {
            c+=b[i];
            a[i]-=b[i];

        }
    }
    cout<<c<<endl;

}