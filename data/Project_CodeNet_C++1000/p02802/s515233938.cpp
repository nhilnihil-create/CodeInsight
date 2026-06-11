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
    int n,m;
    cin>>n>>m;
    map<int,vector<string>>mp;
    for(int i=0;i<m;i++)
    {
        int num;string s;
        cin>>num>>s;
        mp[num].push_back(s);
    }
    int ac=0,wa=0;
    for(auto x:mp)
    {
        int count=0,flag=0;
        for(auto y:x.second)
        {
            if(y=="WA" && flag==0)
            count++;
            if(y=="AC")
            {
                flag=1;
                break;
            }
        }
        if(flag)
        {ac++;wa+=count;}
    }
    cout<<ac<<" "<<wa;
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
