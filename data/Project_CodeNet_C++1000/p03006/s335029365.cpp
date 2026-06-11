#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main(){
    int n;
    cin >> n;
    int x[n],y[n];
    bool a[50]={};
    rep(i,n) cin >> x[i] >> y[i];
    map<pair<int,int>,int> mp;
    rep(i,n){
        rep(j,n){
            if(i==j) continue;
            mp[make_pair(x[j]-x[i],y[j]-y[i])]++;
        }
    }
    int cnt = 0,p=0,q=0,ans=n;
    for(auto i:mp){
        if(cnt < i.second){
            p = i.first.first;
            q = i.first.second;
            cnt = i.second;
        } 
    }
     rep(i,n){
        rep(j,n){
            if(i==j) continue;
            if(x[j]-x[i]==p&&y[j]-y[i]==q) a[j]=1;
        }
    }
    rep(i,n){
        if(a[i]==1) ans--;
    }
    cout << ans << endl;
}