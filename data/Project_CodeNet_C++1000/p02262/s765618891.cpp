#include <bits/stdc++.h>
using namespace std;
long long g[10000005];
long long a[10000005];
long long cnt;
long long isort(long long a[],long long n,long long g)
{
    for(long long i=g;i<n;i++)
    {
        long long v=a[i];
        long long j=i-g;
        while(j>=0&&a[j]>v)
        {
            a[j+g]=a[j];
            j=j-g;
            cnt++;

        }
        a[j+g]=v;
        //cout<<cnt<<endl;
    }
}
void shellsort(long long a[],long long n,long long m)
{
    cnt=0;
    for(long long i=0;i<m;i++)
    {
        isort(a,n,g[i]);
    }
}
int main()
{
    long long n;
    cin>>n;
    for(long long i=0;i<n;i++)
    {
        cin>>a[i];
    }
    long long l=0,e=n;
    while(e>0)
    {
        g[l]=e;
        e/=2;
        l++;
    }
    cout<<l<<endl;
    for(long long i=0;i<l;i++)
    {
        cout<<g[i]<<' ';
    }
    cout<<endl;
    shellsort(a,n,l);
    cout<<cnt<<endl;
    for(long long i=0;i<n;i++) cout<<a[i]<<endl;

}