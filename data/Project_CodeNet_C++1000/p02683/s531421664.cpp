#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()
#define MOD 1000000007
const int INF = 1LL<<30;
 
int a[15][15];
 
int main(){
    int n,m,x;
    cin>>n>>m>>x;
    vector<int> c(n);
 
    rep(i,n){
        cin>>c[i];
        rep(j,m) cin>>a[i][j];
    }
 
    int ans=INF;
    rep(bit,1<<n){
        vector<int> sc(m,0);
        int tmp=0;
        rep(i,n){
            if(bit & 1<<i){
                tmp+=c[i];
                rep(j,m) sc[j]+=a[i][j];
            }
        }
        bool ok=true;
        rep(i,m){
            if(sc[i]<x) ok=false;
        }
        if(ok) ans=min(ans,tmp);
    }
 
    if(ans==INF) ans=-1;
    cout<<ans<<endl;
}