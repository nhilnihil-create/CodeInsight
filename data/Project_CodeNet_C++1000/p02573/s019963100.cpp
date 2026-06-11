#include<bits/stdc++.h>
using namespace std;
#define lli long long int
# define rep(i,n) for(int i=0;i<n;i++)
int p[200005];
int size_a[200005];
int find(int x){
    if(x ==p[x])
        return x;
    return p[x] = find(p[x]);
}
void uni(int u,int v){
    int pu =find(u);
    int pv =find(v);
    if(pu==pv)
    return;
    else{
        p[pu] = pv;
        size_a[pv]+=size_a[pu];
        size_a[pu]=0;
    }
}
void solve(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        p[i]=i;
        size_a[i]=1;
    }

    rep(i,m){
        int u,v;
        cin>>u>>v;
        uni(u,v);
    }
    int ans =0;
    for(int i=1;i<=n;i++)
    ans=max(ans,size_a[i]);
    cout<<ans<<endl;


}
int main()
{
    int t;
    //cin>>t;
    
    t=1;
    while(t--){
        solve();
    }
}