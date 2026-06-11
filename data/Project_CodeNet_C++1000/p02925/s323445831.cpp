#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[1005][1005],pos[1005],n,ans,vis[1005],num;
queue<int> q;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=0;j<n-1;j++)
            cin>>a[i][j];
    for(int i=1;i<=n;i++) q.push(i);
    while(!q.empty()){
        ans++;int sz=q.size();
        for(int o=1;o<=sz;o++){
            int i=q.front();q.pop();
            int x=a[i][pos[i]];
            if(vis[x]==ans||vis[i]==ans) continue;
            if(a[x][pos[x]]==i){
                num++;pos[x]++;pos[i]++;
                if(pos[i]!=n-1) q.push(i);
                if(pos[x]!=n-1) q.push(x);
                vis[x]=ans;vis[i]=ans;
            }
        }
    }
    if(num==n*(n-1)/2) cout<<ans<<endl;
    else cout<<-1<<endl;
}
