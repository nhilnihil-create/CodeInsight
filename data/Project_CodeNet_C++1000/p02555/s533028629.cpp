#include <cstdio>
long long f[2003]={0,0,0,1};
int main(){
    int s;scanf("%d",&s);
    for(int i=4;i<=s;i++) f[i]=(f[i-1]+f[i-3])%1000000007;
    printf("%lld\n",f[s]);
    return 0;
}