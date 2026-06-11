#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;
using graph = vector<vector<int>>;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int main() {
  int N;
  cin >> N;
  vector<pair<int,int>> v(N-1);
  graph g(N);
  vector<vector<int>> ap(N);
  for(int i = 0; i < N-1; i++) {
    int x, y;
    cin >> x >> y;
    v[i]=make_pair(x-1,y-1);
    g[x-1].push_back(y-1);
    g[y-1].push_back(x-1);
    ap[x-1].push_back(i);
    ap[y-1].push_back(i);
  }
  int num = 0;
  for(int i = 0; i < N; i++) {
    chmax(num,(int)g[i].size());
  }
  cout<<num<<endl;
  vector<vector<bool>> cnt(N,vector<bool>(num+1));
  queue<int> q;
  q.push(0);
  vector<bool> seen(N,false);
  seen[0]=true;
  vector<int> col(N-1);
  while(!q.empty()){
    int t = q.front();
    q.pop();
    for(auto nv:g[t]){
      int k=0;
      if(seen[nv]) continue;
      seen[nv] = true;
      q.push(nv);
      for(auto i:ap[t]){
        if(v[i].first==nv||v[i].second==nv) {
          k=i;
          break;
        }
      }
      for(int i = 1; i <= num ; i++) {
        if(cnt[t][i]||cnt[nv][i]) continue;
        cnt[t][i]=true;
        cnt[nv][i]=true;
        col[k]=i;
        break;
      }
    }
  }
  for(int i = 0; i <N-1; i++) {
    cout<<col[i]<<endl;
  }
}