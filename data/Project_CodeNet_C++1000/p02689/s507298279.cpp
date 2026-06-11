#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define INF 1000000000000
using namespace std;
using ll=long long;
using ld=long double;

int main() {
    ll n,m;
    cin>>n>>m;
    vector<ll> h(n);
    vector<ll> a(m);
    vector<ll> b(m);
    rep(i,n)cin>>h[i];
    rep(i,m)cin>>a[i]>>b[i];
    vector<ll> bet_flag(n,1);
    vector<ll> memo(n,0);
    ll ans=0;
    rep(i,m){
        if((h[a[i]-1]-h[b[i]-1])<0){
            if(bet_flag[b[i]-1]!=0){
            bet_flag[b[i]-1]=1;
            }
            bet_flag[a[i]-1]=0;
        }
        else if((h[a[i]-1]-h[b[i]-1])>0){
            if(bet_flag[a[i]-1]!=0){
            bet_flag[a[i]-1]=1;
            }
            bet_flag[b[i]-1]=0;            
        }
        else{
            bet_flag[a[i]-1]=0;
            bet_flag[b[i]-1]=0;
        }
    }
    rep(i,n){
        if(bet_flag[i]==1){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}