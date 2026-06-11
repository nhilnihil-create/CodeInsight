#include <bits/stdc++.h>
using namespace std;

int main () {
  int N;
  string S;
  cin >> N >> S;
  long long R = 0;
  long long G = 0;
  long long B = 0;
  
  for (int i = 0; i < N; i++) {
    if (S.at(i) == 'R'){
      R++;
    }
    else if (S.at(i) == 'G'){
      G++;
    }
    else if (S.at(i) == 'B'){
      B++;
    }
  }
  long long ans = R*G*B;
  
  for (int i = 0; i < N-2; i++) {
    for (int dis = 1; dis < (N-i+1)/2; dis++) {
      if (S.at(i) != S.at(i+dis) && (S.at(i) != S.at(i+dis*2) && S.at(i+dis) != S.at(i+dis*2))){
        ans--;
      }
    }
  }
  cout << ans << endl;
}
  
    
    
    