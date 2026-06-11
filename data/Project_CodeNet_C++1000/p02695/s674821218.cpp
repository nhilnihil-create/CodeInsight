#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int n,m,q;
vector<int> v;
int ans=0;
int a[51],b[51],c[51],d[51];
int check()
{
    int cnt=0;
    for(int i=1;i<=q;i++)
    {
       if(v[b[i]-1]-v[a[i]-1]==c[i])
       cnt+=d[i];
    }
    return cnt;
}
void dfs(int i,int curr)
{
    if(i>n)
    {
       ans=max(ans,check());
       return;
    }
    for(int j=curr;j<=m;j++)
    {
        v.push_back(j);
        dfs(i+1,j);
        v.pop_back();
    }
}
int main()
{
   cin>>n>>m>>q;
   for(int i=1;i<=q;i++)
   {
       cin>>a[i]>>b[i]>>c[i]>>d[i];
   }
   dfs(1,1);
   cout<<ans<<endl;
   return 0;
}