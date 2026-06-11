#include <bits/stdc++.h>
using namespace std;

int getpoint(char hand, int P_R, int P_S, int P_P){
  if (hand == 'r'){
    return P_P;
  }
  else if (hand == 's'){
    return P_R;
  }
  else if (hand == 'p'){
    return P_S;
  }
}

int main(){
  int N, K, P_R, P_S, P_P, ans = 0;
  string T;
  char prehand;
  
  cin >> N >> K >> P_R >> P_S >> P_P;
  cin >> T;
  
  for (int j = 0; j < K; j++){
    prehand = 'z';
  	for (int i = j; i < N; i += K){
      if (i == j){
        ans += getpoint(T.at(i), P_R, P_S, P_P);
        prehand = T.at(i);
      }
      else{
        if (T.at(i) != T.at(i - K) || T.at(i) != prehand){
          ans += getpoint(T.at(i), P_R, P_S, P_P);
          prehand = T.at(i);
        }
        else{
          prehand = 'z';
        }
      }
    }
  }
  
  cout << ans << endl;
}

