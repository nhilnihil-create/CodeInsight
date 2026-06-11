#include <bits/stdc++.h>
using namespace std;
int bitCount(uint bits) {
  int cnt = 0;
  while(bits!=0){
    ++cnt;
    bits&=bits-1;
  }
  return cnt;
}
int main(){
  int n;
  cin>>n;
  vector<vector<int>> board(n,vector<int>(n));
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      board[i][j]=-1;
    }
  }
  for(int i=0;i<n;i++){
    int a;
    cin>>a;
    for(int j=0;j<a;j++){
      int x,y;
      cin>>x>>y;
      x--;
      board[i][x]=y;
    }
  }
  int ans=0;
  for(int i=0;i<(1<<n);i++){
    vector<int> d(n);
    for(int j=0;j<n;j++){
      if(i&(1<<j))d[j]=1;
    }
    bool ok=true;
    for(int j=0;j<n;j++){
      if(d[j]){
        for(int k=0;k<n;k++){
          if(board[j][k]==-1)continue;
          if(board[j][k]!=d[k])ok=false;
        }
      }
    }
    if(ok){
      ans=max(ans,bitCount(i));
    }
  }
  cout<<ans<<endl;
  return 0;
}