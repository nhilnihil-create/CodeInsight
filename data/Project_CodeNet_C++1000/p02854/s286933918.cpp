#include<bits/stdc++.h>
using namespace std;
bool comp(pair<long long int,long long int>a,pair<long long int,long long int>b)
{
    if(a.first==b.first)
    {
        if(a.second<=b.second)
        return true;
        else
        return false;
    }
    if(a.first>b.first)
    return true;
    else return false;
}
bool rev(long long int a,long long int b)
{
    if(a>b)return true;
    else return false;
}
bool compa(pair<string,pair<int,int>>a,pair<string,pair<int,int>>b)
{
    if(a.first==b.first)
    {
        if(a.second.first>b.second.first)
        return true;
        else
        return false;
    }
    if(a.first<b.first)
    return true;
    else 
    return false;
}
long long int gcd(long long int bdda,long long int chota)
{
    if(chota==0)
        return bdda;
    return gcd(chota,bdda%chota);
}
void solve()
{
    long long int n;
    cin>>n;
    long long int a[n],l[n],r[n],sum=0,sumr=0;
    for(long long int i=0;i<n;i++)
    {
        cin>>a[i];
        sum+=a[i];
        l[i]=sum;
    }
    for(long long int i=0;i<n;i++)
    {
        if(i>=0)
        sumr+=a[i];
        r[i]=sum-sumr;
    }
    long long int d=0,m=INT_MAX;
    for(long long int i=0;i<n-1;i++)
    {
        //cout<<l[i]<<" "<<r[i]<<endl;
        d=abs(l[i]-r[i]);
        m=min(d,m);
    }
    cout<<m;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;    
    t=1;

    //cin>>t;
    while(t--)
    {
        solve();
    }
}
