#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,M,d,i,j,a,b;
  cin >> N >> M;
  vector<vector<int>> c(N+1);
  vector<int> H(N+1);

  for(i=1;i<=N;i++)
    cin >> H[i];
  for(i=0;i<M;i++){
    cin >> a >> b;
    c[a].push_back(b);
    c[b].push_back(a);
  }
  
  int ct = 0;
  bool f;
  for(i=1;i<=N;i++){
    if (c[i].size()==0){
      ct++;
    }
    else {
      f = true;
      for(auto x:c[i]){
        if (H[x] >= H[i]){
          f = false;
          break;
        }
      }
      if (f) {
        ct++;
      }
    }
  }
   
  
  cout << ct << endl;

  return 0;
}