#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int N, K, S; cin >> N >> K >> S;
  
  int maxSum = int(pow(10, 9));
  
  if (S == maxSum) {
    
    if (N == K) {
      for (int i = 0; i < N; i++) {
        cout << S;
        if (i != N - 1) cout << " ";
      }
      cout << endl;
    }
    
    else {
      for (int i = 0; i < K; i++) {
        cout << S << " ";
      }
      for (int i = 0; i < N - K; i++) {
        cout << S - 1;
        if (i != N - K - 1) cout << " ";
      }
      cout << endl;
    }
    
  }
  
  else {
    
    if (N == K) {
      for (int i = 0; i < N; i++) {
        cout << S;
        if (i != N - 1) cout << " ";
      }
      cout << endl;
    }
    
    else {
      for (int i = 0; i < K; i++) {
        cout << S << " ";
      }
      for (int i = 0; i < N - K; i++) {
        cout << S + 1;
        if (i != N - K - 1) cout << " ";
      }
      cout << endl;
    }
    
  }
  
}