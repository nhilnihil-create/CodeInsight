#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0; i<(n); i++)
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
int main(){
    ll n,k; cin>>n>>k;
    vector<vector<ll>> edge(n+1);
    rep(i,n-1){
        ll a,b; cin>>a>>b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    ll res=k;
    ll mod=1e9+7;
    queue<ll> que;
    que.push(1);
    vector<bool> used(n+1, false);
    used[1]=true;
    while(!que.empty()){
        ll x=que.front();
        que.pop();
        ll cnt=0;
        for(ll y: edge[x]){
            if(used[y]) continue;
            used[y]=true;
            cnt++;
            if(x==1) res*=k-cnt;
            else res*=k-1-cnt;
            res%=mod;
            que.push(y);
        }
    }
    cout<<res<<endl;
    return 0;
}