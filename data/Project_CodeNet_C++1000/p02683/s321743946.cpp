#include<bits/stdc++.h>
using namespace std ; 
const int INF = 1001001001 ; 


int main () {
  int N ,M ,X  ;
  cin >> N >> M >> X ; 
  
  vector<int> C(N) ; 
  vector<vector<int>> A(N , vector<int>(M)) ;  
  vector<int> sum(M) ; 

  for(int i = 0 ; i< N ; i++){
    cin >> C.at(i) ;
    for(int j = 0 ; j < M ; j++){
      cin >> A.at(i).at(j) ; 
    }
  }
  
  //bit全探索
  int ans = INF ; 
  for(int s = 0 ; s < (1 << N) ; s++){
    int cost = 0 ;
    vector<int> d(M) ;  
    for(int i = 0 ; i < N ; i++){
      if (s >> i&1){ //sのi bitsが立っている時だけ
        cost += C.at(i)  ;
        for(int j = 0 ; j < M ; j++){
          d.at(j) += A.at(i).at(j) ; 
        }
      }
    }
    bool ok = true ; 
    for(int j = 0 ; j < M ; j++) {
      if(d.at(j) < X ) ok = false ;
    }
    if(ok) ans = min(ans,cost) ; 
    
  }
  if(ans == INF) cout << -1 << endl ; 
  else cout << ans << endl;
  
  return 0 ; 
}