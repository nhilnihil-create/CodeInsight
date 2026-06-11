#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define vi vector<int>
#define all(x) (x).begin(),(x).end()
#define INF (1<<30)-1
using ll = long long;
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(b<a) { a=b; return 1; } return 0; }

int main(){
  int n,x,y; cin >> n >> x >> y;
  vector<vi> to(n);
  rep(i,n-1){
    to[i].push_back(i+1);
    to[i+1].push_back(i);
  }
  to[x-1].push_back(y-1);
  to[y-1].push_back(x-1);

  vector<vi> dist(n,vi(n,-1));
  rep(i,n){
    queue<int> q;
    q.push(i);
    while(!q.empty()){
      int now = q.front(); q.pop();
      for(int next : to[now]){
        if(0 <= dist[i][next]) continue;
        dist[i][next] = dist[i][now] + 1;
        q.push(next);
      }
    }
  }

  vi cnt(n);
  rep(i,n){
    for(int j = i+1; j < n; j++){
      cnt[dist[i][j]]++;
    }
  }
  rep(i,n-1) cout << cnt[i] << "\n";
  cout << "\n";
  return 0;
}
