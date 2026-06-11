#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
using namespace std;
int main(void){
    ll n,m;cin>>n>>m;
    vector<vector<ll>> t(m+10);
    rep(i,n){
        ll a,b;cin>>a>>b;
        if(a>m)continue;
        t[a].push_back(b);
    }
    ll res=0;
    priority_queue<ll> que;
    rep(i,m+1){
        if(i==0)continue;
        rep(j,t[i].size())que.push(t[i][j]);
        if(que.size()==0)continue;
        res+=que.top();que.pop();
    }
    cout<<res<<endl;
}