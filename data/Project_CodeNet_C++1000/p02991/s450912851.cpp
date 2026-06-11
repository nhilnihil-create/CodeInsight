#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<ll,ll> l_l;
const int INF=1001001000;
const int mINF=-1001001000;
const ll LINF=1010010010010010000;
int main(){
    int n,m;cin >> n >> m;
    vector<int> G[100010];
    for(int i=0;i<m;i++){
        int u,v;cin >> u >> v;
        u--;v--;
        G[u].push_back(v);
    }
    int sv,tv;cin >> sv >> tv;
    sv--;tv--;
    queue<P> q;
    q.push({sv,0});
    vector<vector<int>> dist(n,vector<int>(3,INF));
    dist[sv][0]=0;
    while(!q.empty()){
        int nowp=q.front().first;
        int nowd=q.front().second;
        q.pop();
        for(auto next: G[nowp]){
            if(dist[next][(nowd+1)%3]!=INF) continue;
            dist[next][(nowd+1)%3]=dist[nowp][nowd]+1;
            q.push({next,(nowd+1)%3});
        }
    }
    ll ans=dist[tv][0];
    if(dist[tv][0]==INF) ans=-1;
    else ans/=3;
    cout << ans << endl;
    return 0;
}