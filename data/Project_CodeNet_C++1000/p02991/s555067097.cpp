#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<pii,int> ppii;

int INF = 1000000;
map<pii, int> dist;
map<pii, vector<pii>> v;

bool operator>(ppii x, ppii y){
  return x.second > y.second;
}

void shortest_path(int start){
  priority_queue<ppii, vector<ppii>, greater<ppii>> que;

  dist[make_pair(start,0)] = 0;
  que.push(make_pair(make_pair(start,0),0));

  while(!que.empty()){
    ppii now = que.top();
    que.pop();
    pii now_v = now.first;
    ll now_dist = now.second;
    // cerr << now_v << " " << now_dist << endl;
    if(dist[now_v] < now_dist) continue;

    for(auto next_v: v[now_v]){
      // cerr << now_v <<  " " << next_v  << " " << now_dist << endl;
      if(dist[next_v] > now_dist + 1 ){
        dist[next_v] = now_dist + 1;
        que.push(make_pair(next_v, dist[next_v]));
      }
    }
  }
}

int main(){
  cout << setprecision(10);
  int N,M; cin >> N >> M;

  for(int i= 0; i < M; i++){
    int s,t; cin >> s >> t;
    s--; t--;
    v[make_pair(s,0)].push_back(make_pair(t,1));
    v[make_pair(s,1)].push_back(make_pair(t,2));
    v[make_pair(s,2)].push_back(make_pair(t,0));
  }
  for(int i = 0; i < N; i++){
    for(int j = 0; j < 3; j++){
      dist[make_pair(i,j)] = INF;
    }
  }

  int S,T; cin >> S >> T;
  S--; T--;
  shortest_path(S);
  auto d = dist[make_pair(T,0)];
  cout << (d == INF ? -1 : d/3) << endl;
  
}
