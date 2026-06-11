#include<bits/stdc++.h>
using namespace std;
#define int long long 
int32_t main()
{
    int n,k;
    cin>>n>>k;
    int a[n+1];
    int vis[n+1];
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        vis[i]=0;
    }
    vector<int>v;
    v.push_back(1);
    int x=1;
    vis[1]=1;
    int u;
    while(1)
    {
        if(vis[a[x]]==0)
        {
            v.push_back(a[x]);
            vis[a[x]]=1;
            x=a[x];
            //cout<<x<<"\n";
        }
        else
        {
            u=a[x];
            break;
        }
    }
    int z=v.size();
    int f;
    for(int i=0;i<z;i++)
    {
        if(v[i]==u)
        {
            f=i;
            break;
        }
    }
    if(k<z)
    cout<<v[k]<<"\n";
    else
    {
        k-=z;
        z-=f;
        k%=z;
        cout<<v[f+k]<<"\n";
    }
    
}