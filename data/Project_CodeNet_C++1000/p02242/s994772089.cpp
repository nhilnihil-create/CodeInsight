
#include<bits/stdc++.h>

using namespace std;

const int maxn=1e2+5;
const int inf=(1<<21);
const int white=0;
const int gray=1;
const int black=2;

int n,m[maxn][maxn];

void dijkstra()
{
    int minv,d[maxn],book[maxn];
    for(int i=0;i<n;i++){
        d[i]=inf;
        book[i]=0;
    }
    d[0]=0;
    while(1){
        minv=inf;
        int u=-1;
        for(int i=0;i<n;i++){
            if(minv>d[i]&&book[i]==0){
                u=i;
                minv=d[i];
            }
        }
        if(u==-1){
            break;
        }
        book[u]=1;
        for(int v=0;v<n;v++){
            if(book[v]==0&&(d[v]>d[u]+m[u][v])){
                    d[v]=d[u]+m[u][v];
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<i<<" "<<(d[i]==inf?-1:d[i])<<endl;
    }
}

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            m[i][j]=inf;
        }
    }
    int u,k,v,c;
    for(int i=0;i<n;i++){
        cin>>u>>k;
        for(int j=0;j<k;j++){
            cin>>v>>c;
            m[u][v]=c;
        }
    }
    dijkstra();
    return 0;
}
/*
5
0 3 2 3 3 1 1 2
1 2 0 2 3 4
2 3 0 3 3 1 4 1
3 4 2 1 0 1 1 4 4 3
4 2 2 1 3 3 
*/
