#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rrep(ri,n) for(int ri = (int)(n-1); ri >= 0; ri--)
#define rep2(i,x,n) for(int i = (int)(x); i < (int)(n); i++)
#define repit(itr,x) for(auto itr = x.begin(); itr != x.end(); itr++)
#define rrepit(ritr,x) for(auto ritr = x.rbegin(); ritr != x.rend(); ritr++)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using namespace std;
using P = pair<int, int>;

void fc(queue<pair<int, int>> &now, vector<queue<int>> &vq, int i, vector<bool> &cl){
  if(vq.at(i).size() == 0) return;
  int j = vq.at(i).front();
  if(cl.at(i) == true || cl.at(j) == true) return;
  if(vq.at(j).size() > 0 && vq.at(j).front() == i){
    cl.at(i) = true; cl.at(j) = true;
    now.push(make_pair(i, j));
  }
}

void qc(vector<queue<int>> &vq, vector<bool> &cl){
  rep(i, cl.size()){
    if(cl.at(i) == true){
      vq.at(i).pop();
      cl.at(i) = false;
    }
  }
}

int main(){
  int n;
  cin >> n;
  vector<queue<int>> vq(n);
  vector<bool> cl(n);
  rep(i, n){
    rep(j, n-1){
      int a;
      cin >> a;
      a--;
      vq.at(i).push(a);
    }
  }
  queue<pair<int, int>> now;
  int ans = 0;
  rep(i, n){
    if(vq.at(i).front() > i && vq.at(i).size() == n-1){
      fc(now, vq, i, cl);
    }
  }
  qc(vq, cl);
  while(!now.empty()){
    queue<pair<int, int>> nx;
    ans++;
    while(!now.empty()){
      auto p = now.front(); now.pop();
      // cerr << ans << " " << p.first << " " << p.second << endl;
      fc(nx, vq, p.first, cl);
      fc(nx, vq, p.second, cl);
    }
    qc(vq, cl);
    now = nx;
  }
  rep(i, n){
    if(vq.at(i).size() != 0){
      cout << -1 << endl;
      return 0;
    }
  }
  cout << ans << endl;
  return 0;
}