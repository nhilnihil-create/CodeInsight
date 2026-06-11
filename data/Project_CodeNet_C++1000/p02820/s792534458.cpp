#include <bits/stdc++.h>
using namespace std;

int main () {
  int N,K,R,S,P;
  string T;
  cin >> N >> K >> R >> S >> P >> T;
  int score = 0;
  
  for (int i = 0; i < N; i++) {
    if (i < K || T.at(i) != T.at(i-K)){
      if (T.at(i) == 'r'){
        score += P;
      }
      else if (T.at(i) == 's'){
        score += R;
      }
      else if (T.at(i) == 'p'){
        score += S;
      }
    }
    else {
      T.at(i) = 'a';
    }
  }
  cout << score << endl;
}
      
      
  
    
  
   