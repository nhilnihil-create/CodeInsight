#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
using namespace std;
using ll=long long;
constexpr ll mod=1000000007;
constexpr int inf=1000000000;
constexpr ll linf=1000000000000000000;

int main(){
    int n,m,x;
    cin>>n>>m>>x;
    int c[n];
    int a[n][m];
    rep(i,n){
        cin>>c[i];
        rep(j,m)cin>>a[i][j];
    }
    ll ans=linf;
    rep(i,1<<n){
        ll v=0;
        int sum[m]={};
        rep(j,n){
            if(i&(1<<j)){
                v+=c[j];
                rep(k,m){
                    sum[k]+=a[j][k];
                }
            }
        }
        bool flag=true;
        rep(j,m){
            if(sum[j]<x)flag=false;
        }
        if(flag)ans=min(v,ans);
    }
    if(ans==linf)ans=-1;
    cout<<ans<<endl;
}
