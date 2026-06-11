#include<cstdio>
#include<iostream>
#include<algorithm>
#include<queue>
#include<set>
#include<cstring>
#include<cmath>
using namespace std;
const int N = 10;
const int M = 10;
const int INF = 0x3f3f3f3f;
int d[N][N],n;
int main()
{
    int m,a,b,c;
    while(cin>>m&&m){
        for(int i=0;i<N;i++)
            fill(d[i],d[i]+N,INF);
        n=0;
        while(m--){
            scanf("%d%d%d",&a,&b,&c);
            d[a][b]=d[b][a]=c;
            n=max(max(n,a+1),b+1);
        }
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
                }
            }
        }
        int sum,msum=INF;
        int id=0;
        for(int i=0;i<n;i++){
            sum=0;
            for(int j=0;j<n;j++){
                if(i==j)continue;
                sum+=d[i][j];
            }
            if(sum<msum){
                msum=sum;
                id=i;
            }
        }
        printf("%d %d\n",id,msum);
    }

    return 0;
}