#include <bits/stdc++.h>
using namespace std;

int main() {
  int N; cin >> N;
  vector<long> H(N);
  for (int i =0; i<N; i++) {
    long a; cin >> a; 
    H.at(i) = a;
  }
  
  int maxMove =0;
  int move =0;
  for (int i =1; i<N; i++) {
    if (H.at(i) <= H.at(i-1)) {
      move++;
    } else {
      maxMove = max(move,maxMove);
      move =0;
    }
  }     
  maxMove = max(move,maxMove);    
  cout << maxMove << endl;
}