#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
#define rep(i, n) for(int i=0;i<(int)n;i++)
#define PI acos(-1)
#define fast_io ios_base::sync_with_stdio(false) ; cin.tie(0); cout.tie(0);
ll mod=1e9+7;
ll gcd(ll a, ll b){if(b==0) return a; return gcd(b, a%b);}
int main(){
    fast_io

    int n;
    cin>>n;
    vector<vector<int>> G(n);
    vector<P> vp;
    for(int i=1;i<n;i++){
        int a, b;
        cin>>a>>b;
        a--;b--;
        G[a].emplace_back(b);
        G[b].emplace_back(a);
        vp.emplace_back(a, b);
    }
    int K=0;
    map<P,int> I;
    vector<int> cs(n,0); //color of edge between its parent

    vector<int> used(n, 0);
    queue<int> que;
    used[0]=1;
    que.emplace(0);
    while(!que.empty()){
        int v=que.front();
        que.pop();
        if(K<(int)G[v].size()) K=G[v].size();
        int cur=1;
        for(int u: G[v]){
            if(used[u]) continue;
            if(cur == cs[v]) cur++;
            cs[u] = I[make_pair(u, v)] = I[make_pair(v, u)] = cur++;
            used[u]=1;
            que.emplace(u);
        }
    }

    cout<<K<<endl;
    for(auto p:vp) cout<<I[p]<<endl;
    return 0;
}