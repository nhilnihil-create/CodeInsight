#include <iostream>
#include <bits/stdc++.h>

#define rep(i,z) for(int i = 0; i<(int)(z); i++)
#define rep1(i,z) for(int i = 1; i<=(int)(z); i++)
 
using namespace std;

typedef long long ll;
const ll MOD=1e9+7;
using pear = pair<int,int>;





int main(){
    int n, m, x; cin>>n >>m >>x;
    int c[n], a[n][m];
    ll ans=0;
    rep(i,n){
        cin>>c[i];
        rep(j,m) cin>>a[i][j];
    ans+=c[i];
    }
    ans++;
    int fal=ans;
    int all= 1<<n;
    for(int mask=0; mask<all; mask++){
        vector<int> level(m);
        ll now=0;
        for(int i = 0; i < n; i++){
            if((mask>>i)&1){
                now+=c[i];
                for(int j=0; j<m; j++) level[j]+= a[i][j];
            }
            
        }
        bool ok = true;
        rep(j,m) if(level[j]<x) ok=false;
        if(ok) ans = min(ans,now);
    }
    if(fal==ans) cout<<-1<<endl;
    else cout<<ans<<endl;   
}