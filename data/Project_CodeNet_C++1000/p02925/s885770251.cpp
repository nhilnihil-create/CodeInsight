#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int INF = 1<<30;
const ll mod = 1000000007LL;

int main() {
  int N;
  cin>>N;
  vector<queue<int>> vq(N);
  for(int i = 0; i < N; i++){
    for(int j = 0; j < N-1;j++){
      int x;
      cin>>x;
      vq[i].push(x-1);
    }
  }
  vector<int> v(N);
  for(int i = 0; i < N; i++) {
    v[i]=vq[i].front();
    vq[i].pop();
  }
  bool can = true;
  int day = 0;
  while(true){
    bool n = false;
    vector<bool> m(N,false);
    for(int i = 0; i < N; i++) {
      if(m[i])continue;
      if(v[i]==-1)continue;
      if(m[v[i]]) continue;
      if(v[v[i]]==i){
        int t = v[i];
        if(vq[i].empty()) v[i]=-1;
        if(!vq[i].empty()){
          v[i]=vq[i].front();
          vq[i].pop();
        }
        if(vq[t].empty()) v[t] = -1;
        if(!vq[t].empty()){
          v[t]=vq[t].front();
          vq[t].pop();
        }
        m[i]=true;
        m[t]=true;
        n = true;
      }
    }
    day++;
    if(!n) break;
  }
  for(auto x:v) if(x!=-1)can = false;
  if(can)cout<<day-1<<endl;
  else cout<<-1<<endl;
}
  