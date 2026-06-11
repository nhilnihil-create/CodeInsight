#include <stdio.h>
int main(){
    int n,a,m,temp,graph[101][101];
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            graph[i][j]=0;
        }
    }
    for(int i=0;i<n;i++){
        scanf("%d%d",&a,&m);
        for(int j=0;j<m;j++){
            scanf("%d",&temp);
            graph[a][temp]++;
        }
    }
    for(int i=1;i<=n;i++){
        printf("%d",graph[i][1]);
        for(int j=2;j<=n;j++){
            printf(" %d",graph[i][j]);
        }
        printf("\n");
    }
}