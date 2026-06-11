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
    long long int b[n-1];
    for(long long int i=0;i<n-1;i++)cin>>b[i];
    long long int a[n];
    a[0]=b[0];
    for(long long int i=1;i<=n-2;i++)
    {
        a[i]=min(b[i-1],b[i]);
    }

    a[n-1]=b[n-2];
    long long int sum=0;
    for(auto x:a)sum+=x;
    cout<<sum;
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
