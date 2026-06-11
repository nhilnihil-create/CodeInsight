/*そーなのかー
　　　＿
　 '´　　 ヽ
 ./ ﾉﾉ））)）〉
〈《.! ﾟ ヮﾟﾉ》
　⊂!::V::!つ
　 く::::::::〉
　　 し'ﾉ*/
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,k;
  int64_t e=0;
  cin >> n >> k;
  vector<int64_t>h(n);
  for(int i=0;i<n;i++){
  cin >> h.at(i);
  }
  sort(h.begin(),h.end());
  if(k<=n){
    for(int i=0;i<n-k;i++){
    e+=h.at(i);
    }
  cout << e << endl;  
  }
  else{
  cout << 0 << endl;
  }
}