#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<stack>
#include<queue>
#define INF 0x3f3f3f3f
#define lowbit(x) x & -x
#define lson root<<1,l,mid
#define rson root<<1|1,mid+1,r
using namespace std;
typedef long long ll;
const int mod=1e9+7;
const int N=3e5+5;
int fx[N],fy[N];
int x[N],y[N];
int main(){
#ifdef Mizp
    freopen("in.txt","r",stdin);
#endif
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=k;i++){
        scanf("%d%d",&x[i],&y[i]);
        fx[x[i]]++;
        fy[y[i]]++;
    }
    int maxx=0,maxy=0;
    for(int i=1;i<=n;i++){
        maxx=max(fx[i],maxx);
    }
    for(int i=1;i<=m;i++){
        maxy=max(fy[i],maxy);
    }
    int flag=0;
    for(int i=1;i<=k;i++){
        if(fx[x[i]]==maxx && fy[y[i]]==maxy)
            flag++;

    }
    int cntx=0,cnty=0;
    for(int i=1;i<=n;i++){
        if(maxx==fx[i])
            cntx++;
    }
    for(int i=1;i<=m;i++){
        if(maxy==fy[i])
            cnty++;
    }
    if(flag==1ll*cntx*cnty)
        printf("%d\n",maxx+maxy-1);
    else 
        printf("%d\n",maxx+maxy);
    return 0;
}
