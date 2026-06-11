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
using pll = pair<long, long>;
#define fix20 cout << fixed << setprecision(20)
#define YES cout << "Yes" << endl
#define NO cout << "No" << endl
#define rep(i,n) for(int i=0; i<(int)(n);i++)
#define REP(i,s,t) for(int i=s; i<t; i++)
#define RNG(i,s,t,u) for(int i=s; i<t; i+=u)
#define MOD 1000000007
#define all(vec) vec.begin(), vec.end()

vector<vi> Graph(100100); 

struct Node{
  int now;
  int sub;
  long cost;
};

bool operator<(const Node &a, const Node &b){
  if(a.cost != b.cost){
    return a.cost < b.cost;
  }else{
    return a.now * 3 + a.sub < b.now * 3 + b.sub;
  }
}

bool operator>(const Node &a, const Node &b){
  if(a.cost != b.cost){
    return a.cost > b.cost;
  }else{
    return a.now * 3 + a.sub > b.now * 3 + b.sub;
  }
}

int main(){
  int n,m;
  cin >> n >> m;
  rep(i,m){
    int u,v;
    cin >> u >> v;
    u--;v--;
    Graph.at(u).push_back(v);
  }
  int s,t;
  cin >> s >> t;
  s--;t--;
  vector<vector<long>> dist(n+1,vl(3,1e9));
  dist.at(s).at(0) = 0;
  priority_queue<Node, vector<Node>, greater<Node>> que;
  que.push(Node{s,0,0});
  while(que.size()){
    Node node = que.top();
    que.pop();
    if(node.cost > dist.at(node.now).at(node.sub)) continue;
    for(int next : Graph.at(node.now)){
      if(dist.at(node.now).at(node.sub) == 1e9) continue;
      if(dist.at(next).at((node.sub+1)%3) > dist.at(node.now).at(node.sub) + 1){
        dist.at(next).at((node.sub+1)%3) = dist.at(node.now).at(node.sub) + 1;
        que.push(Node{next,(node.sub+1)%3,dist.at(next).at((node.sub+1)%3)});
      }
    }
  }
  if(dist.at(t).at(0) == 1e9) cout << -1 << endl;
  else cout << dist.at(t).at(0)/3 << endl;
}