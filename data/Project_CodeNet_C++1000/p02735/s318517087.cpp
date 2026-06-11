#include <bits/stdc++.h>
using namespace std;

int main(){
  int H,W;
  cin >> H >> W ;
  vector<string> S(H);
  for(int i=0;i<H;i++){
    cin >> S.at(i);
  }
  vector<vector<int>> ans(H, vector<int>(W, 1001));
  ans.at(0).at(0)=0;
  if(S.at(0).at(0)=='#'){
    ans.at(0).at(0)++;
  }
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      int x=1000,y=1000;
      if(j!=0){
        if(S.at(i).at(j)==S.at(i).at(j-1)){
          x=ans.at(i).at(j-1);
        }else{
          x=ans.at(i).at(j-1)+1;
        }
      }
      if(i!=0){
        if(S.at(i).at(j)==S.at(i-1).at(j)){
          y=ans.at(i-1).at(j);
        }else{
          y=ans.at(i-1).at(j)+1;
        }
      }
      ans.at(i).at(j)=min(ans.at(i).at(j),min(x,y));
    }
  }
  if(S.at(H-1).at(W-1)=='#'){
    ans.at(H-1).at(W-1)++;
  }
  cout << ans.at(H-1).at(W-1)/2 << endl;
  
}
    