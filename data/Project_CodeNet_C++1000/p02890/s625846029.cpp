#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+50;

int n,c[maxn],d[maxn],kd[maxn],f[maxn],res[maxn];

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        int ai;
        scanf("%d",&ai);
        ++c[ai];
    }
    for(int i=1;i<=n;++i) ++d[c[i]];
    for(int i=0;i<=n;++i) kd[i]=i*d[i];
    for(int i=1;i<=n;++i){
        d[i]+=d[i-1];
        kd[i]+=kd[i-1];
    }
    for(int i=1;i<=n;++i){
        f[i]=(kd[i]+i*(d[n]-d[i]))/i;
    }
    int pos=n,ans=0,i=1;
    while(pos){
        while(pos<=f[i]) ++ans,++i;
        res[pos--]=ans;
    }
    for(int i=1;i<=n;++i) printf("%d\n",res[i]);
    return 0;
}