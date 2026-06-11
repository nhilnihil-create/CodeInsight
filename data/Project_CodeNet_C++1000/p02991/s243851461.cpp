#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vb = vector<bool>;
using vl = vector<long>;
using vs = vector<string>;
using vvi = vector<vector<int>>;
using vvb = vector<vector<bool>>;
using vvc = vector<vector<char>>;
using pil = pair<int, long>;
using pll = pair<long, long>;
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
  //int sub;
  long rec;
};

bool operator<(const Node &a, const Node &b){
  if(a.rec != b.rec){
    return a.rec < b.rec;
  }else{
    return a.now < b.now;
  }
}
bool operator>(const Node &a, const Node &b){return (b < a);}
bool operator<=(const Node &a, const Node &b){return !(b < a);}
bool operator>=(const Node &a, const Node &b){return !(a < b);}

//vector<vector<pair<int,long>>> Graph : from -> pair<int,long> to, cost

vector<long> Dijkstra(vector<vector<pair<int,long>>> &Graph, int s){
  priority_queue<Node, vector<Node>, greater<Node>> que;
  vector<long> dist(Graph.size(), 1e16);

  dist.at(s) = 0;
  que.push(Node{s, 0});

  while(que.size()){
    Node node = que.top();
    que.pop();
    if(node.rec > dist.at(node.now)) continue;

    for(pair<int,long> nP : Graph.at(node.now)){
      int next = nP.first;
      long cost = nP.second;
      if(dist.at(next) > dist.at(node.now) + cost){
        dist.at(next) = dist.at(node.now) + cost;
        que.push(Node{next, dist.at(next)});
      }
    }
  }
  
  return dist;
}

int main(){
  int n,m;
  cin >> n >> m;
  vector<vector<pair<int,long>>> Graph(3*n);
  rep(i,m){
    int u,v;
    cin >> u >> v;
    u--;v--;
    rep(j,3){
      Graph.at(u*3+j).push_back(pil(v*3+(j+1)%3, 1));
    }
  }
  int s,t;
  cin >> s >> t;
  s--;t--;
  vector<long> dist = Dijkstra(Graph, 3*s);
  if(dist.at(3*t) == 1e16) cout << -1 << endl;
  else cout << dist.at(3*t)/3 << endl;
}