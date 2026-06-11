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
    long long int a[n];
    for(long long int i=0;i<n;i++)cin>>a[i];
    long long int med=0;
    for(long long int i=0;i<n;i++)med+=a[i];
    med/=n;
    long long int ans=0,val=0;
    for(long long int i=0;i<n;i++)val+=(med-a[i])*(med-a[i]);
    med++;
    for(long long int i=0;i<n;i++)ans+=(med-a[i])*(med-a[i]);
    cout<<min(ans,val)<<endl;
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
