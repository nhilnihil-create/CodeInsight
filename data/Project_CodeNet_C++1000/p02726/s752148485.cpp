#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rrep(ri,n) for(int ri = (int)(n-1); ri >= 0; ri--)
#define rep2(i,x,n) for(int i = (int)(x); i < (int)(n); i++)
#define rrep2(ri,x,n) for(int ri = (int)(n-1); ri >= (int)(x); ri--)
#define repit(itr,x) for(auto itr = x.begin(); itr != x.end(); itr++)
#define rrepit(ritr,x) for(auto ritr = x.rbegin(); ritr != x.rend(); ritr++)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using namespace std;

int main(){
  int n, x, y;
  cin >> n >> x >> y;
  x--; y--;
  vector<vector<int>> gr(n);
  rep(i, n){
    int pr = i - 1, nx = i + 1;
    if(i != 0) gr.at(i).push_back(pr);
    if(i != n-1) gr.at(i).push_back(nx);
  }
  gr.at(x).push_back(y);
  gr.at(y).push_back(x);
  vector<int> ans(n-1, 0);
  rep(i, n-1){
    vector<int> d(n, -1);
    queue<int> q;
    q.push(i);
    d.at(i) = 0;
    while(!q.empty()){
      int now = q.front(); q.pop();
      for(auto nx : gr.at(now)){
        if(d.at(nx) != -1) continue;
        d.at(nx) = d.at(now) + 1;
        q.push(nx);
      }
    }
    rep2(j, i+1, n){
      ans.at(d.at(j)-1)++;
    }
  }
  for(auto o : ans){
    cout << o << endl;
  }
  return 0;
}