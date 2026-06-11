#include<bits/stdc++.h>
using namespace std ; 

int g[15][15] ; 

int main() {
  int n ; 
  cin >> n ; 
  for(int i = 0 ; i < n ; i++){
    for(int j = 0 ; j < n ; j++){
      g[i][j] = -1 ; 
    }
  }
  
  for(int i = 0 ; i < n ; i++){
    int m ;
    cin >> m ; 
    for(int j = 0 ; j < m ; j++){
      int a , x ; 
      cin >> a >> x ; 
      --a ; 
      g[i][a] = x ; //入力でiがjについてなんて言っているか
    }
  }
  
  int ans = 0 ; 
  for(int i = 0 ; i < (1<<n) ; i++){//bit演算子でiを2進数にする ex) 00000,00001,00010...
    vector<int> d(n) ; 
    for(int j = 0 ; j < n ; j++) if(i >>j&1){//1が何桁目にあるかをみる
      d[j] = 1 ; //1があった桁は1にする
    }
    
    bool ok = true ; 
    for(int j = 0 ; j <n ; j++){
      if(d[j]){
        for(int k = 0 ; k <n ; k++){
          if(g[j][k] == -1) continue ; //jがkについて何も言っていない =>　飛ばす
          if(g[j][k] != d[k]) ok = false ; //jがkについて言っていること!=d[k]　=>false        
        }
      }
    }
    if(ok) ans = max(ans , __builtin_popcount(i)) ; 
  }
  cout << ans << endl ; 
  return 0 ; 
}