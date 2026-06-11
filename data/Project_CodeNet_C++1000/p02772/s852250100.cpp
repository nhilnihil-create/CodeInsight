#include<bits/stdc++.h>
using namespace std;
long long int mod97=1000000007;
double pi=3.1415926536;
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
    long long int a[n];
    for(long long int i=0;i<n;i++)cin>>a[i];
    for(long long int i=0;i<n;i++)
    {
        if(a[i]%2==0)
        {
            if(a[i]%3!=0 && a[i]%5!=0)
            {
                cout<<"DENIED";return;
            }
        }
    }
    cout<<"APPROVED";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;    
    t=1;

    //cin>>t;
    int count=1;
    while(t--)
    {
        
        solve();
    }
}
