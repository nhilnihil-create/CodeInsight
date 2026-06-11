#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0;i<(n);++i)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define all(x) (x).begin(), (x).end()
#define PI 3.14159265358979323846264338327950L
using namespace std;
typedef long long ll;
typedef long double ld;
int main() {
    int n,m,x;
    cin>>n>>m>>x;
    int c[n],a[n][m];
    rep(i,n){
        cin>>c[i];
        rep(j,m) cin>>a[i][j];
    }
    ll ans=123456789;
    rep(bi,(1<<n)){
        vector<int> level(m);
        ll cost=0;
        rep(i,n){
            if((bi>>i)&1){
                cost+=c[i];
                rep(j,m) level[j]+=a[i][j];
            }
        }
        bool flag=true;
        rep(j,m) if(level[j]<x) flag=false;
        if(flag) ans=min(ans,cost);
    }
    if(ans==123456789) cout<<-1;
    else cout<<ans;
}