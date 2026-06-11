#include <bits/stdc++.h>
using namespace std;
# define LL long long


int main(){
    int n,m,x_;
    scanf("%d%d%d",&n,&m,&x_);
    int g[n][m+1];
    for(int x=0;x<n;x++){
        for (int y=0;y<m+1;y++){
            scanf("%d",&g[x][y]);
        }
    }
    int cost=10000000,pres=0;
    
    int arr[m+1]={0};
    for (int i=1;i<(1<<n);i++){
        for(int x=0;x<n;x++){
            if ((i>>x)&1) {
                pres+=g[x][0];
                for (int y=1;y<m+1;y++){
                    arr[y]+=g[x][y];
                }
            }
        }
        int ans=1;
        for (int y=1;y<m+1;y++){
            ans=(ans & (arr[y]>=x_));
            arr[y]=0;
        }
        if (ans) cost=min(cost,pres);
        pres=0;
    }
    if (cost==10000000) printf("-1");
    else printf("%d",cost);
}