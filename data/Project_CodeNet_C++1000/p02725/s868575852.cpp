#include<bits/stdc++.h>
using namespace std;


int main()
{
    int k,n;
    cin>>k>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int total =0;
    for(int i=1;i<n;i++)
    {
        total += a[i] - a[i-1];
    }
    total += a[0] + k-a[n-1];

    int m = INT_MIN;
    for(int i=1;i<n;i++)
    {
        m = max( m , a[i] - a[i-1]);
    }
    m = max( m , a[0] + k-a[n-1]);
    cout<<total - m;
}