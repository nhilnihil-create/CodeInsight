#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rrep(ri,n) for(int ri = (int)(n-1); ri >= 0; ri--)
#define rep2(i,x,n) for(int i = (int)(x); i < (int)(n); i++)
#define repit(itr,x) for(auto itr = x.begin(); itr != x.end(); itr++)
#define rrepit(ritr,x) for(auto ritr = x.rbegin(); ritr != x.rend(); ritr++)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using namespace std;

void bfs(vector<vector<int>> &gr, vector<bool> &chk, vector<int> &deg, vector<int> &ans, int i){
  queue<int> q;
  q.push(i);
  chk.at(i) = true;
  while(!q.empty()){
    int now = q.front(); q.pop();
    ans.push_back(now);
    for(auto nx : gr.at(now)){
      deg.at(nx)--;
      if(deg.at(nx) == 0 && chk.at(nx) == false){
        chk.at(nx) = true;
        q.push(nx);
      }
    }
  }
}

int main(){
  int v, e;
  cin >> v >> e;
  vector<int> deg(v, 0);
  vector<vector<int>> gr(v, vector<int>());
  rep(i, e){
    int s, t;
    cin >> s >> t;
    gr.at(s).push_back(t);
    gr.at(t).push_back(s);
    deg.at(t)++;
  }
  vector<bool> chk(v, false);
  vector<int> ans;
  rep(i, v){
    if(deg.at(i) == 0 && chk.at(i) == false){
      bfs(gr, chk, deg, ans, i);
    }
  }

  for(int i : ans){
    cout << i << endl;
  }
  return 0;
}
