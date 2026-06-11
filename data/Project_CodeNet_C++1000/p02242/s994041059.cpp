#include <bits/stdc++.h>
using namespace std;
#define INFTY (1<<30)

int n;
vector<int> color(101,0),d(101,INFTY),p(101);
vector<vector<int>> M(101,vector<int>(101,INFTY));

void dijkstra(int s){
    d[s]=0;
    p[s]=-1;
    while(1){
        int u;
        int mincost=INFTY;
        for(int i=0;i<n;i++){
            if(color[i]!=2&&d[i]<mincost){
                mincost=d[i];
                u=i;
            }
        }
        if(mincost==INFTY) break;
        color[u]=2;
        for(int v=0;v<n;v++){
            if(color[v]!=2&&M[u][v]!=INFTY){
                if(d[u]+M[u][v]<d[v]){
                    d[v]=d[u]+M[u][v];
                    p[v]=u;
                    color[v]=1;
                }
            }
        }
    }
}

int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        int a,b,c,k;
        cin>>a>>k;
        for(int j=0;j<k;j++){
            cin>>b>>c;
            M[a][b]=c;
        }
    }

    dijkstra(0);

    for(int i=0;i<n;i++){
        cout<<i<<' '<<d[i]<<endl;
    }
}
