#include <bits/stdc++.h>
#define ll long long
#define pi 3.14159265358979
#define rep(i,n) for(ll i=0;i<n;i++)
using namespace std;

int main(){
    ll n,m,h[100005],memo[100005],x,y,ans=0;
    cin >> n >> m;
    rep(i,n){
        cin >> h[i];
        memo[i]=0;
    }
    rep(i,m){
        cin >> x >>y;
        if(h[x-1]>=h[y-1]){
            memo[y-1]=1;
        }
        if(h[y-1]>=h[x-1]){
            memo[x-1]=1;
        }
    }
    rep(i,n){
        if(memo[i]==0){
            ans++;
        }
    }
    cout << ans;
}