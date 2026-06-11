#include<bits/stdc++.h>
using namespace std;
#define int long long
#define PI pair<int,int>
const int maxm=1e5+5;
const int mod=1e9+7;
vector<int>g[maxm];
int fac[maxm];
int inv[maxm];
int d[maxm];
int n,k;
int ppow(int a,int b,int mod){
    int ans=1%mod;a%=mod;
    while(b){
        if(b&1)ans=ans*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return ans;
}
void dfs(int x,int fa){
    for(int v:g[x]){
        if(v==fa)continue;
        dfs(v,x);
        d[x]++;
    }
}
void init(){
    fac[0]=1;
    for(int i=1;i<maxm;i++)fac[i]=fac[i-1]*i%mod;
    inv[maxm-1]=ppow(fac[maxm-1],mod-2,mod);
    for(int i=maxm-2;i>=0;i--)inv[i]=inv[i+1]*(i+1)%mod;
}
int A(int n,int m){
    if(m<0||m>n)return 0;
    return fac[n]*inv[n-m]%mod;
}
signed main(){
    init();
    cin>>n>>k;
    for(int i=1;i<n;i++){
        int a,b;cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1,1);
    int ans=k*A(k-1,d[1])%mod;
    for(int i=2;i<=n;i++){
//        cout<<d[i]<<endl;
        ans=ans*A(k-2,d[i])%mod;
    }
    cout<<ans<<endl;
    return 0;
}
/*

*/
