#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll=long long;
int main(){
    int n;
    cin>>n;
    vector<int>x(n),y(n);
    map<pair<int,int>,int>mp;
    rep(i,n)cin>>x[i]>>y[i];
    rep(i,n){
        rep(j,n){
            if(i==j)continue;
            mp[make_pair(x[i]-x[j],y[i]-y[j])]++;
        }
    }
    int ans=0;
    for(auto&p:mp){
        ans=max(ans,p.second);
    }
    cout<<n-ans<<endl;
}