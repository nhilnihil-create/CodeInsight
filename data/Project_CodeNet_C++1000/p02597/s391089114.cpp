#include "bits/stdc++.h"
using namespace std;

int solve(int N,string c){
  int cnt = 0;
  int j=N-1; //後ろのカーソル
  for(int i=0;i<j;i++){
    if(c[i] == 'W'){
      for(;;j--){
        if(i == j)
          return cnt;
        else if(c[j] == 'R'){
          cnt++; j--;//入れ替え
          break;
        }
      }
    }
  }
  return cnt;
}

int main(){
  
  int N;
  string c;
  cin >> N >> c;

  cout << solve(N,c);
  return 0;
}