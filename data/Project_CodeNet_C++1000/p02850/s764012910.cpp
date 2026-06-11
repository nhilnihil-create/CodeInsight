#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define INF (1LL<<50)
#define MOD 1000000007

using Edge = pair<int,int>; // (隣接頂点, 辺番号)
using Graph = vector<vector<Edge>>;

int main(){
    int N;
    cin >> N;
    Graph G(N,vector<Edge>());
    rep(i,N-1){
        int a,b;
        cin >> a >> b;
        a--;b--;
        G[a].push_back(make_pair(b,i));
        G[b].push_back(make_pair(a,i));
    }
    int cnt=0;
    rep(i,N) cnt = max(cnt,(int)G[i].size());
    cout << cnt << endl;
    deque<pair<int,int>> dq;
    dq.push_back(make_pair(0,-1));
    vector<int> seen(N);
    while(!dq.empty()){
        auto p = dq.front(); dq.pop_front();
        int node = p.first;
        int c = p.second;
        int num = 1;
        for(int i=0;i<G[node].size();i++){
            int n_node = G[node][i].first;
            int n_edge = G[node][i].second;
            if(seen[n_edge]>0){
                continue;
            }
            if(num==c){
                num++;
            }
            dq.push_back(make_pair(n_node,num));
            seen[n_edge] = num;
            num++;
        }
    }
    rep(i,N-1) cout << seen[i] << endl;
    return 0;
}