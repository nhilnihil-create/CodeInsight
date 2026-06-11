#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,M;
  cin >> N >> M;
  
  if (N <= M){
    for (int i = 0; i < M; i++) {
      cout << N;
    }
  }
  else {
    for (int i = 0; i < N; i++) {
      cout << M;
    }
  }
  cout << endl;
  
}

