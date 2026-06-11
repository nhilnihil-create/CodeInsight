#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
template<class T> inline bool chmax(T& a, T b) {
  if (a < b) { a = b; return 1; }
  return 0; }
template<class T> inline bool chmin(T& a, T b) {
  if (a > b) { a = b; return 1; }
  return 0; }

int main(void){
  int n; cin >> n;
  vector<vector<int>> to(n,vector<int>());
  int a[n-1],b[n-1];
  rep(i,n-1){
    cin >> a[i] >> b[i];
    a[i]--; b[i]--;
    to[a[i]].push_back(b[i]);
    to[b[i]].push_back(a[i]);
  }
  queue<int> q;
  q.push(0);
  int color_num = 0;
  vector<int> ans(n);
  ans[0]=0;
  vector<int> parent(n,-1);
  queue<int> p;
  p.push(0);
  while(!p.empty()){
    int k = p.front();
    p.pop();
    for(int c: to[k]){
      if(parent[c] == -1){
        parent[c] = k;
      }
      else continue;
      p.push(c);
    }
  }
  parent[0] = -1;
  while(!q.empty()){
    int k = q.front();
    q.pop();
    int count = 1;
    int i = 1;
    for(int c : to[k]){
      if(c == parent[k]) continue;
      if(i == ans[k]){
        i++;
        ans[c] = i;
      }
      else{
        ans[c] = i;
      }
      q.push(c);
      i++;
      count++;
    }
    if(k == 0) count--;
    color_num = max(color_num,count);
  }
  cout << color_num << endl;
  for(int i = 0; i < n-1; i++){
    if(parent[a[i]] == b[i]){
      cout << ans[a[i]] << endl;
    }
    else if(parent[b[i]] == a[i]){
      cout << ans[b[i]] << endl;
    }
  }
  return 0;
}
