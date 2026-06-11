#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N,K,S;
  cin >> N >> K >> S;
  
  for (int i = 0; i < K; i++) {
    cout << S << ' ';
  }
  for (int i = 0; i < N-K; i++) {
    if (S != 1000000000){
      cout << S+1 << ' ';
    }
    else {
      cout << S-1 << ' ';
    }
  }
  cout << endl;
}