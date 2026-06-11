#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vb = vector<bool>;
using vl = vector<long>;
using vs = vector<string>;
using vvi = vector<vector<int>>;
using vvb = vector<vector<bool>>;
using vvc = vector<vector<char>>;
using pii = pair<int, int>;
using pil = pair<int, long>;
using pll = pair<long, long>;
using vc = vector<char>;
#define fix20 cout << fixed << setprecision(20)
#define YES cout << "Yes" << endl
#define NO cout << "No" << endl
#define rep(i,n) for(int i=0; i<(int)(n);i++)
#define REP(i,s,t) for(int i=s; i<t; i++)
#define RNG(i,s,t,u) for(int i=s; i<t; i+=u)
#define MOD 1000000007
#define all(vec) vec.begin(), vec.end()

struct Node{
  int now;
  int sub;
  long cost;
};

struct Edge{
  int from;
  int to;
  long cost;
};

bool operator<(const Node &a, const Node &b){
  if(a.cost != b.cost){
    return a.cost < b.cost;
  }else{
    return a.now < b.now;
  }
}
bool operator>(const Node &a, const Node &b){return (b < a);}
bool operator<=(const Node &a, const Node &b){return !(b < a);}
bool operator>=(const Node &a, const Node &b){return !(a < b);}

//vector<vector<Edge>> Graph(n);

vector<vector<long>> Dijkstra(vector<vector<Edge>> &Graph, int s){ //最小コスト
  priority_queue<Node, vector<Node>, greater<Node>> que;
  vector<vector<long>> dist(Graph.size(), vector<long>(3, 1e16));

  dist.at(s).at(0) = 0;
  que.push(Node{s, 0, 0});

  while(que.size()){
    Node node = que.top();
    que.pop();
    int v = node.now;
    int sv = node.sub;
    if(node.cost > dist.at(v).at(sv)) continue;
    for(Edge edge : Graph.at(v)){
      int nv = edge.to;
      long cost = edge.cost;
      int nsv = (sv + 1) % 3;
      if(dist.at(nv).at(nsv) > dist.at(v).at(sv) + cost){
        dist.at(nv).at(nsv) = dist.at(v).at(sv) + cost;
        que.push(Node{nv, nsv, dist.at(nv).at(nsv)});
      }
    }
  }
  return dist;
}

int main(){
  int n,m;
  cin >> n >> m;
  vector<vector<Edge>> Graph(n);
  rep(i,m){
    int u,v;
    cin >> u >> v;
    u--;v--;
    Graph.at(u).push_back(Edge{u,v,1});
  }
  int s,t;
  cin >> s >> t;
  s--;t--;
  vector<vector<long>> dist = Dijkstra(Graph, s);
  if(dist.at(t).at(0) % 3 == 0) cout << dist.at(t).at(0) / 3 << endl;
  else cout << -1 << endl;
}