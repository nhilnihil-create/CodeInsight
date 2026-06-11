#include<bits/stdc++.h>
using namespace std;


int main(){
  int h,w,a,b;
  cin >> h >> w >> a >> b;
  vector<vector<int>> ans(h,vector<int>(w,0));
  for(int i=0;i<h;++i){
    for(int j=0;j<w;++j){
      if((i<b && j<a) || (i>=b && j>=a)){
        ans[i][j]=1;
      }
    }
  }
  for(int i=0;i<h;++i){
    for(int j=0;j<w;++j){
      cout << ans[i][j];
    }
    cout << endl;
  }
  return 0;
}
