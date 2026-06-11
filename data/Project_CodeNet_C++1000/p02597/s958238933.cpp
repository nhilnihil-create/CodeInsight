#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  string S;
  cin >> S;
  int r = 0;//右にあり取り換えておくもの,あらかじめ数える
  int w = 0;//左にあるのを見つけたらカウント
  int ans = 200001;
  
  for(int i = 0; i < S.size(); i++){
    if(S.at(i) == 'R'){
      r++;
    }
  }
  if(ans > max(r,w)) ans = max(r,w);
 
  for(int i = 0; i < S.size(); i++){
    if(S.at(i) == 'R'){
      r--;
    }
    else w++;
    
    if(ans > max(r,w)) ans = max(r,w);
  }
  
  cout << ans << endl;
  
}