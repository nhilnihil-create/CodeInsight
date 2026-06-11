#include <bits/stdc++.h>
using namespace std;
# define LL long long


int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    int h[n+1],con[n+1];
    for (int i=1;i<=n;i++) {
        scanf("%d",&h[i]);
        con[i]=1;
    }
    for (int i=0;i<m;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        if (h[u]<h[v]) con[u]=0;
        else if (h[u]>h[v]) con[v]=0;
        else {
            con[u]=0;
            con[v]=0;
        }
    }
    int ans=0;
    for (int i=1;i<=n;i++){ 
        // cout<<con[i]<<" ";
        if (con[i]==1) ans+=1;
    }
    // cout<<"\n";
    printf("%d",ans);
    
    
}