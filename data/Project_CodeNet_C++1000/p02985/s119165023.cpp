//Author - Rahil Malhotra
#include <bits/stdc++.h>
using namespace std;
 
template <typename T> void print(T t) { cout<<t<<endl; }
template<typename T, typename... Args> void print(T t, Args... args) { cout<<t<<" "; print(args...); }
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define int long long
#define double long double

int n,k;
vector<int>v[100005];
int vis[100005];
int mod=1e9+7;
int dfs(int pos,int par)
{
    vis[pos]=1;
    int sz=1;
    for(auto i:v[pos])
        sz+=vis[i];
    int ans=1;
    for(auto i:v[pos])
        if(i!=par)
        {
            ans=(ans*(((k-sz)*dfs(i,pos))%mod))%mod;
            sz++;
        }
    return ans;
}
int32_t main()
{
    IOS;
    cin>>n>>k;
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    if(n==1)
        return cout<<k,0;
    if(n==2)
        return cout<<(k*(k-1))%mod,0;
    int st=-1;
    for(int i=1;i<=n;i++)
    {
        if(st==-1 && v[i].size()==1)
            st=i;
        if(v[i].size()+1>k)
            return cout<<0,0;
    }
    int ans=(k*(k-1))%mod;
    vis[st]=1;
    ans=(ans*dfs(v[st][0],st))%mod;
    print(ans);
}
