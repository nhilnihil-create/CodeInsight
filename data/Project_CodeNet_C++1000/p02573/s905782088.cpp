#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,m;
  cin >> n >> m;
  vector<vector<int>> G(n);
  for(int i=0;i<m;i++){
    int a,b;
    bool al=false;
    cin >> a >> b;
    for(int x:G[a-1]){
      if(x==b-1) al=true;
    }
    if(!al){
      G[a-1].push_back(b-1);
      G[b-1].push_back(a-1);
    }
  } 
  int ans1=0,ans2=0;
  vector<bool> F(n,false);
  queue<int> bf;
  for(int i=0;i<n;i++){
    if(F[i]) continue;
    
    bf.push(i);
    F[i]=true;
    ans2=0;
    
    while(!bf.empty()){
      int k=bf.front();
      bf.pop();
      for(int x:G[k]){
        if(!F[x]) {
          bf.push(x);
          F[x]=true;
        }
      }
      ans2++;
    }
    
    ans1=max(ans1,ans2);
  }
  cout << ans1 << endl;     
  return 0;
}