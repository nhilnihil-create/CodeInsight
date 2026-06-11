#include<bits/stdc++.h>
using namespace std;
#define lint long long
#define inf 1000000000000000000
#define mod 1000000007
#define MAX 5005
#define pb push_back
#define vit vector<int>::iterator
typedef pair<lint,lint> pii;
lint P[MAX],C[MAX],Cy[MAX],Cysum[MAX],Cylen[MAX],Cymax[MAX][MAX];
void dfs(lint u,lint id){
    Cy[u]=id;
    Cylen[id]++;
    Cysum[id]+=C[u];
    if(!Cy[P[u]]) dfs(P[u],id);
}
void dfs2(lint u,lint l,lint sum){
    lint id=Cy[u];
    sum+=C[u];
    Cymax[id][l]=max(Cymax[id][l],sum);
    if(l<Cylen[id]) dfs2(P[u],l+1,sum);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    lint n,k;
    cin>>n>>k;
    for(lint i=1;i<=n;i++) cin>>P[i];
    for(lint i=1;i<=n;i++) cin>>C[i];
    lint id=0;
    for(lint i=1;i<=n;i++){
        if(!Cy[i]){
            id++;
            dfs(i,id);
        }
    }
    for(lint i=1;i<=id;i++){
        for(lint j=0;j<=Cylen[i];j++){
            Cymax[i][j]=-inf;
        }
    }
    for(lint i=1;i<=n;i++){
        dfs2(i,1,0);
    }
    lint ans=-inf;
    for(lint i=1;i<=id;i++){
     //   cout<<Cysum[i]<<' '<<Cylen[i]<<endl;
        if(k<=Cylen[i]){
            for(lint j=1;j<=k;j++){
                ans=max(ans,Cymax[i][j]);
            }
        }
        else if(Cysum[i]<=0){
            for(lint j=1;j<=Cylen[i];j++){
                ans=max(ans,Cymax[i][j]);
            }
        }
        else{
            lint sm1=-inf;
            for(lint j=1;j<=Cylen[i];j++){
                sm1=max(sm1,Cymax[i][j]);
            }
            lint sm2=-inf,en=k%Cylen[i];
            for(lint j=1;j<=en;j++){
                sm2=max(sm2,Cymax[i][j]);
            }
            lint tims=k/Cylen[i];
         //   cout<<tims<<' '<<sm1<<' '<<sm2<<endl;
            ans=max(ans,(tims-1)*Cysum[i]+sm1);
            ans=max(ans,tims*Cysum[i]+sm2);
        }
    }
    cout<<ans;
    return 0;
}
/*
10 58
9 1 6 7 8 4 3 2 10 5
695279662 988782657 -119067776 382975538 -151885171 -177220596 -169777795 37619092 389386780 980092719
*/
