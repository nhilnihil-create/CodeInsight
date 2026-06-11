#include<bits/stdc++.h>
#define rep(i,f,n) for(ll i=(f); (i) < (n); i++)
#define repe(i,f,n) for(ll i=(f); (i) <= (n); i++)
using namespace std;
using ll = long long;

ll INF = 1LL << 60;
int N;
void
bfs(int index, vector<vector<int>>& tree, vector<vector<int>>& ans)
{
  vector<int> dist(N + 1, -1);
  dist[index] = 0;
  queue<int> q;
  for(int value: tree[index]){
    q.push(value);
    //if(index <= value){
      dist[value] = 1;
      ans[index][dist[value]] += 1;
    //}
  }

  while(!q.empty()){
    int value = q.front();
    q.pop();
    for(int next :tree[value]){
      if(dist[next] != -1) continue;
      //if(index >= next) continue;
      dist[next] = dist[value] + 1;
      ans[index][dist[next]] += 1;
      q.push(next);
    }
  }
}


int 
main() {

  int X, Y; cin >> N >> X >> Y;
  vector<vector<int>> tree(N + 1);
  vector<vector<int>> ans (N + 1, vector<int>(N + 1));

  rep(i, 1, N){
    tree[i].push_back(i + 1);
    tree[i + 1].push_back(i);
  }
  if(X != Y && abs(X - Y) != 1){
    tree[X].push_back(Y);
    tree[Y].push_back(X);
  }
  
  repe(i, 1, N){
    bfs(i, tree, ans);
  }

  rep(i, 1, N){
    int out = 0;
    repe(k, 1, N){
      out += ans[k][i];
    }
    cout << out / 2 << endl;
  }
}
