#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
    int n,m,x;
    cin>>n>>m>>x;
    vector<int>c(n),sum(m);
    vector<vector<int>>a(n,vector<int>(m));
    rep(i,n){
        cin>>c[i];
        rep(j,m){
            cin>>a[i][j];
            sum[j]+=a[i][j];
        }
    }
    rep(i,m)if(sum[i]<x){cout<<-1<<endl; return 0;}
    int ans=1e9;
    rep(i,1<<n){
        int cnt=0;
        rep(j,m)sum[j]=0;
        rep(j,n){
            if(i&(1<<j)){
                cnt+=c[j];
                rep(k,m)sum[k]+=a[j][k];
            }
        }
        bool ok=true;
        rep(j,m)if(sum[j]<x)ok=false;
        if(ok)ans=min(ans,cnt);
    }
    cout<<ans<<endl;
    return 0;
}