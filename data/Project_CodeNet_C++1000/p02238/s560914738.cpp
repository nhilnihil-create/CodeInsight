#include<stdio.h>

int d[100],f[100],n,g[100][100],time=1;

int func(int m){
    d[m]=time++;
    int i,j;
    for(i=0;i<n;i++){
        if(g[m][i]==1 && d[i]==0){
            func(i);
        }
    }
    f[m]=time++;
}

int main(void){
    int i, j, u, k, v;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d %d",&u,&k);
        for(j=0;j<k;j++){
            scanf("%d",&v);
            g[u-1][v-1]=1;
        }
    }
    func(0);
    for(i=0;i<n;i++){
        if(d[i]==0){
            func(i);
        }
    }
    for(i=0;i<n;i++){
        printf("%d %d %d\n",i+1,d[i],f[i]);
    }
    return 0;
}