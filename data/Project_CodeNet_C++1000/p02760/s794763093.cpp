#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(k,i,n) for(ll i=k;i<n;++i)
int main(void){
    // Your code here!
    ll a[3][3];
    rep(0,i,3){
        rep(0,j,3)cin>>a[i][j];
    }
    bool ans=false;
    ll n;
    cin>>n;
    ll b[n];
    rep(0,i,n)cin>>b[i];
    rep(0,i,n){
        rep(0,j,3){
            rep(0,k,3)if(a[j][k]==b[i])a[j][k]=-1;
        }
    }
    rep(0,i,3){
        bool t=true;
        rep(0,j,3)if(a[i][j]!=-1)t=false;
        if(t)ans=true;
    }
    rep(0,j,3){
        bool t=true;
        rep(0,i,3)if(a[i][j]!=-1)t=false;
        if(t)ans=true;
    }
    bool t=true;
    rep(0,i,3)if(a[i][i]!=-1)t=false;
    if(t)ans=true;
    t=true;
    rep(0,i,3)if(a[i][2-i]!=-1)t=false;
    if(t)ans=true;
    if(ans)cout<<"Yes";
    else cout<<"No";
}