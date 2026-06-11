#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int N, K, R, S, P; cin >> N >> K >> R >> S >> P;
  
  string T; cin >> T; int64_t sum = 0;
  
  vector<bool> vec(N, true);
  
  for (int i = 0; i < N - K; i++) {
    
    if (vec[i] && T.at(i) == T.at(i + K)) vec[i + K] = false;
    
  }
  
  for (int i = 0; i < N; i++) {
    
    if (vec[i] == false) continue;
    
    if (T.at(i) == 'r') sum += P;
    if (T.at(i) == 's') sum += R;
    if (T.at(i) == 'p') sum += S;
    
  }
  
  cout << sum << endl;
  
}