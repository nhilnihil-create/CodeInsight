//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pp pair<int,int>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define ld long double
#define al(a) (a).begin(),(a).end()
#define mk make_pair
#define check cout<<"?"<<endl;

ll MOD=1000000007;
ll mod=998244353;
int inf=1000001000;
ll INF=1e18+5;

int main() {
    int n,t,s,v; cin>>n>>t;
    vector<vector<int>> dpl(n,vector<int>(3001,0)),dpr(n,vector<int>(3001,0));
    vector<pp> g(n);
    rep(i,n){
        int a,b; cin>>a>>b;
        g[i]=mk(a,b);
    }
    for(int i=1;i<=n-1;i++){
        tie(s,v)=g[i-1];
        rep(j,3001){
            dpl[i][j]=dpl[i-1][j];
            if(j>=s){
                if(dpl[i][j]<dpl[i-1][j-s]+v)
                dpl[i][j]=dpl[i-1][j-s]+v;
            }
        }
    }
    for(int i=1;i<=n-1;i++){
        tie(s,v)=g[n-i];
        rep(j,3001){
            dpr[i][j]=dpr[i-1][j];
            if(j>=s){
                if(dpr[i][j]<dpr[i-1][j-s]+v)
                dpr[i][j]=dpr[i-1][j-s]+v;
            }
        }
    }
    int ans=0,cnt;
    rep(i,n){
        rep(j,t){
            cnt=g[i].second+dpl[i][j]+dpr[n-1-i][t-1-j];
            ans=max(ans,cnt);
        }
    }
    cout<<ans<<endl;
}
