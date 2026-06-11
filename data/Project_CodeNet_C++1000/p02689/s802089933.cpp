#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;
using namespace std;

int main(){
    int n,m;
    int a,b,ans=0;
    cin>>n>>m;
    vector<int> h(n);
    vector<vector<int>> v(n);
    rep(i,n) cin>>h[i];
    rep(i,m){
        cin>>a>>b;
        a--;b--;
        v[a].push_back(h[b]);
        v[b].push_back(h[a]);
    }
    rep(i,n){
        if(v[i].empty()){
            ans++;
            continue;
        }
        sort(v[i].begin(),v[i].end(),greater<int>());
        if(h[i]>v[i][0]) ans++;
    }
    cout<<ans<<endl;
}
