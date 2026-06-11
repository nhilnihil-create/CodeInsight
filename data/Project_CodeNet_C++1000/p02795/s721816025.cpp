#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
const int maxn=105;
int H,W,N;
int a[maxn][maxn];
int main(){
    int ans=0;
    scanf("%d%d%d",&H,&W,&N);
    int x=max(H,W);
    if(N%x)
        ans=N/x+1;
    else
    {
        ans=N/x;
    }
    printf("%d\n",ans);
    return 0;
}
