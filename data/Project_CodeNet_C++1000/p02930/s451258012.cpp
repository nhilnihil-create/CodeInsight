#include<bits/stdc++.h>
using namespace std;
const int N=505;
int a[N][N];
void dfs(int l,int r,int k)
{
    if(l==r) return;
    int m=l+r>>1;
    for(int i=l;i<=m;i++)
        for(int j=m+1;j<=r;j++)
            a[i][j]=k;
    dfs(l,m,k+1);dfs(m+1,r,k+1);
}
int main()
{
    int n;scanf("%d",&n);
    if(n==2){printf("1\n");return 0;}
    dfs(1,n,1);
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
        printf(j==n?"%d\n":"%d ",a[i][j]);
}
