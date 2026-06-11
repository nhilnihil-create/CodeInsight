#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

int main() {
  int n,q;
  cin >> n >> q;
  vector<vector<int>> to(n);
  rep(i,n-1){
      int x,y;
      cin >> x >> y;
      x--;y--;
      to[x].push_back(y);
      to[y].push_back(x);
  }
  queue<int> que;
  que.push(0);
  vector<int> cnt(n,0);
  vector<int> ans(n,-1);
  rep(i,q){
      int x,y;
      cin >> x >> y;
      x--;
      cnt[x]+=y;
  }
  while(!que.empty()){
      int x=que.front();que.pop();
      for(int y:to[x]){
          if(ans[y]!=-1) continue;
          que.push(y);
          cnt[y]+=cnt[x]; 
      }
      ans[x]++;
  }
  rep(i,n) cout << cnt[i] << endl;
}