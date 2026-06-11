//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define all(v) v.begin(), v.end()
using in = int64_t;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define Yes cout<<"Yes"<<endl
#define No cout<<"No"<<endl
#define yes cout<<"yes"<<endl
#define no cout<<"no"<<endl
const double PI=3.14159265358979323846;
const in MOD = 1000000007;
const in INF=1e18+7;
const int inf=1e9+7;
using P=pair<int,int>;
vector<int> dx={0,1,-1,0};
vector<int> dy={1,0,0,-1};

struct dijkstra{
    struct edge{int to; int cost;};
    vector<vector<edge>> graph;
    vector<int> dist;
    int MAX_dist;

    // 頂点数を入れる
    dijkstra(int n): graph(n,vector<edge>(0)){
        MAX_dist = inf;
    dist.resize(n,MAX_dist);
    }

    // 一方向に辺を追加
    void add(int from, int to, int cost){
        graph[from].push_back({to, cost});
        return;
    }

    // 双方向に辺を追加
    void add_both(int edge_one, int edge_two, int cost){
        graph[edge_one].push_back({edge_two,cost});
        graph[edge_two].push_back({edge_one,cost});
        return;
    }

    // 計算する
    void culc(int s){
        priority_queue<P, vector<P>, greater<P>> que;
        dist[s]=0;
        que.emplace(0,s);
        while(!que.empty()){
            P p=que.top();
            que.pop();
            int v=p.second;
            if(dist[v]<p.first) continue;
            for(auto e: graph[v]){
                if(dist[e.to]>dist[v]+e.cost){
                    dist[e.to]=dist[v]+e.cost;
                    que.emplace(dist[e.to],e.to);
                }
            }
        }
    }

    // 距離を出す
    int ans(int t){
        return dist[t];
    }
};

int main(){
ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cout << fixed << setprecision(10);
    int n,m;
    cin>>n>>m;
    vector<vector<int>> g(n,vector<int>(0));
    int x,y;
    rep(i,m){
        cin>>x>>y;
        x --,y --;
        g[x].emplace_back(y);
    }
    int s,t;
    cin>>s>>t;
    s--,t--;

    dijkstra dk(n*3);
    rep(i,n){
        for(auto z:g[i]){
            dk.add(i,z+n,1);
            dk.add(i+n,z+n+n,1);
            dk.add(i+n+n,z,1);
        }
    }

    dk.culc(s);
    int ans=dk.ans(t);
    if(ans==dk.MAX_dist) cout<<-1<<endl;
    else cout<<ans/3<<endl;
    return 0;
}/*
./problem.exe
*/