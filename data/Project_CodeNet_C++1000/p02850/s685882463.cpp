#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 10000000000 + 7;

int main(){
  cout << setprecision(10);
  int N; cin >> N;

  vector<pii> edge(N-1); // 枝が結んでいる頂点
  vector<int> edge_col(N-1, -1); // 色
  vector<map<int,int>> node_col(N); // 各頂点で使われた色

  vector<vector<int>> node_edge(N); // 各頂点が持つ枝
  queue<int> q;

  for(int i = 0; i < N-1; i++){
    int tmp1,tmp2; cin >> tmp1 >> tmp2;
    tmp1--; tmp2--;

    edge[i] = make_pair(tmp1,tmp2);

    node_edge[tmp1].push_back(i);
    node_edge[tmp2].push_back(i);
  }

  int max_deg = 0;
  int max_deg_node;
  for(int i = 0; i < N; i++){
    int deg = node_edge[i].size();

    if(deg > max_deg){
      max_deg_node = i;
      max_deg = deg;
    }
  }

  q.push(max_deg_node);
  while(!q.empty()){
    int now = q.front();
    q.pop();

    for(int e: node_edge[now]){
      if(edge_col[e] != -1){
        continue;
      } 

      int node_1 = edge[e].first;
      int node_2 = edge[e].second;

      int next = (node_1 == now ? node_2 : node_1);
      q.push(next);
      // cerr << now << " " << next << endl;

      int index = node_col[now].size();
      // 最悪max_deg回探索する
      for(int time = 0; time < max_deg; time++){
        index += time;
        index %= max_deg;
        if(node_col[now][index] == 0 && node_col[next][index] == 0){
          node_col[now][index] = 1;
          node_col[next][index] = 1;
          edge_col[e] = index;
          break;
        }
      }
    }
  }

  cout << max_deg << endl;
  for(int i = 0; i < N-1; i++){
    cout << edge_col[i] + 1 << endl;
  }



}
