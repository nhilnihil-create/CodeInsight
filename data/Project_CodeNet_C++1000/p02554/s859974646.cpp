#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;
#define ll long long 
const int maxn=1000010;
const ll mod=1e9+7;
int n;
ll f[maxn][2][2];
int main(){
    scanf("%d",&n);
    f[1][0][0]=8;
    f[1][1][0]=1;
    f[1][0][1]=1;
    for (int i=2;i<=n;++i){
        f[i][0][0]=f[i-1][0][0]*8%mod;
        f[i][1][0]=(f[i-1][0][0]+f[i-1][1][0]*9%mod)%mod;
        f[i][0][1]=(f[i-1][0][0]+f[i-1][0][1]*9%mod)%mod;
        f[i][1][1]=(f[i-1][0][1]+f[i-1][1][0]+f[i-1][1][1]*10%mod)%mod;
    }
    printf("%lld",f[n][1][1]%mod);
    return 0;
}