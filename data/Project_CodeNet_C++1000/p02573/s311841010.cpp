//tanzim bin nasir
#include<bits/stdc++.h>
typedef long long ll;
#define ff first
#define ss second
using namespace std;
void fast()
{
ios::sync_with_stdio(false);
cin.tie(NULL); cout.tie(NULL);
}
ll gcd(ll a,ll b)
{
    if(b==0)
    return a;
    else
    gcd(b,a%b);
}
ll lcd(ll a,ll b)
{
    return (a*b)/gcd(a,b);
}
bool vis[200005];
vector<int> a[200005];
int dfs(int n)
{
    int ans=0;
    if(!vis[n])
    {
        vis[n]=true;
        ++ans;
        for(int i=0;i<a[n].size();i++)
        {
            ans+=dfs(a[n][i]);
        }
    }
    return ans;
}
int main()
{
    int n,m,x,y;
    cin>>n>>m;
    memset(vis,false,n);
    for(int i=0;i<m;i++)
    {
        cin>>x>>y;
        --x,--y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    int ans=0;
    for(int i=0;i<n;i++)
    {
        if(!vis[i])
        {
           ans=max(ans,dfs(i));
        }
    }
    cout<<ans<<endl;
}

