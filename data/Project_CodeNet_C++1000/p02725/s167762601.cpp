#include<bits/stdc++.h>
using namespace std;
int main()
{

    long k,n;
    cin>>k>>n;
    long a[n];
    for(long i=0;i<n;i++)cin>>a[i];
    sort(a,a+n);
    int d=INT_MAX;
    int st,ed;
    st=min(k-(a[1]-a[0]),a[n-1]-a[0]);
    d=st;
    for(int i=1;i<n-1;i++)
    {
        if(d>(k-(a[i+1]-a[i])))
            d=k-(a[i+1]-a[i]);
        if(d>(k-(a[i]-a[i-1])))
            d=k-(a[i]-a[i-1]);
    }
    cout<<d;



}
