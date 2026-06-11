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
    int n;
    cin>>n;
    map<string,int>mp;
    for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        mp[s]++;
    }
    int m=0;
    for(auto x:mp)
    m=max(m,x.second);
    for(auto x:mp)
    if(x.second==m)
    cout<<x.first<<endl;
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
