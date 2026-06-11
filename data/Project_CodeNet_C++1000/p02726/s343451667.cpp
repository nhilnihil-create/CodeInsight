#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>
#include <queue>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i=0;i < (int)(n);i++)

int main(){
  int n,x,y;
  cin >> n >> x >> y;
  vector<vector<int>> g(n);
  rep(i,n-1){
    g[i].push_back(i+1);
    g[i+1].push_back(i);
  }
  g[--x].push_back(--y);
  g[y].push_back(x);
  
  vector<int> anss(n);
  
  rep(i,n){
    vector<int> dis(n,-1);
    dis[i] = 0;
    queue<int> q;
    q.push(i);
    while(!q.empty()){
      //cout << "{";
      //rep(p,n){
        //cout << dis[p] << " ";
      //}
      //cout << "}" << endl;
      int tmp = q.front();q.pop();
      for (auto nx :g[tmp]){
        if (dis[nx] == -1){
          q.push(nx);
          dis[nx] = dis[tmp] + 1;
        }
      }
    }
    for (int k = 0; k < n; k++){
      anss[dis[k]]++;
    }
  }
  for (int k = 1; k < n;k++){
    cout << anss[k]/2 << endl;
  }

  return 0;
}
