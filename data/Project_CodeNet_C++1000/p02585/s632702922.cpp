#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e3+5;
int n;
ll k,a[N],p[N],cnt[N]={0},sum[N][N]={0};
ll dfs(ll i){
    ll u=i,num=1,pos=1;
    while(p[i]!=u){
        num++;
        i=p[i];
        sum[u][pos]=sum[u][pos-1]+a[i];
      pos++;
    }
    sum[u][pos]=sum[u][pos-1]+a[u];
    return num;
}

int main()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>p[i];
    for(int i=1;i<=n;i++) cin>>a[i];
    ll ans=-1e18;
    for(int i=1;i<=n;i++){
        cnt[i]=dfs(i);
        ll mx1=-1e18,mx2=-1e18;
        for(int j=1;j<=cnt[i];j++){
            mx1=max(mx1,sum[i][j]);
        }
        for(int j=1;j<=(k%cnt[i]?k%cnt[i]:cnt[i]);j++){
            mx2=max(mx2,sum[i][j]);
        }
        if(k>cnt[i]){
            ll num=(k%cnt[i])?k/cnt[i]:k/cnt[i]-1;
            ans=max(ans,max(mx1,num*sum[i][cnt[i]]+mx2));
        }
        else ans=max(ans,mx2);
    }
    cout<<ans;
}
