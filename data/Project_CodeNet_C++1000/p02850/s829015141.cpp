#include<bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
using namespace std;
typedef long long ll;

int main(){
    ll n,a,b;
    cin>>n;
    vector<vector<ll>> adj(n);
    map<pair<ll,ll>,ll> mp;
    rep(i,n-1){
        cin>>a>>b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
        mp[make_pair(a,b)]=i;
        mp[make_pair(b,a)]=i;
    }
    vector<ll> col(n-1,-1);
    queue<pair<ll,ll>> q;
    q.push(make_pair(0,-1));
    ll cmx=0;
    while(!q.empty()){
        ll now=q.front().first,pcol=q.front().second;
        q.pop();
        ll ccnt=0;
        rep(i,adj[now].size()){
            if(col[mp[make_pair(now,adj[now][i])]]==-1){
                if(ccnt==pcol) ccnt++;
                col[mp[make_pair(now,adj[now][i])]]=ccnt;
                q.push(make_pair(adj[now][i],ccnt));
                cmx=max(cmx,ccnt);
                ccnt++;
            }
        }
    }
    cout<<cmx+1<<endl;
    rep(i,n-1) cout<<col[i]+1<<endl;
    return 0;
}