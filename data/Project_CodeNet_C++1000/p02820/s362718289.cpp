#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int N, K, R, S, P;

int calc_score(char T){
  
  if(T=='r'){
    return P;
  }else if(T=='s'){ 
    return R;
  }else if(T=='p'){
    return S;
  }

}

int main(){
  cin >> N >> K >> R >> S >> P;
  string T;
  cin >> T;
  
  int score = 0;
  
  bool wins[K];
  for(int i=0; i<K; i++) wins[i] = false;
  
  for(int i=0; i<N; i++){
    if(T[i]!=T[i-K] || wins[i%K]==false){
      score += calc_score(T[i]);
      wins[i%K] = true;
    }else {
      wins[i%K] = false;
    }
  }
    
  cout << score << endl;
  return 0;
}