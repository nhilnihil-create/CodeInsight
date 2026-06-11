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
    int n,k,q;
    cin>>n>>k>>q;
    int s[n+1];
    for(int i=0;i<n+1;i++)s[i]=k-q;
    for(int i=0;i<q;i++)
    {
        int num;
        cin>>num;
        s[num]++;
    }
    for(int i=1;i<n+1;i++)
    {
        if(s[i]<=0)
        cout<<"No"<<endl;
        else cout<<"Yes"<<endl;
    }
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
