#include <bits/stdc++.h>
using namespace std;
int INF = 1000000000;
int main(){
  int N, K, S;
  cin >> N >> K >> S;
  vector<int> A(N);
  if (S != INF){
    for (int i = 0; i < K; i++){
      A[i] = S;
    }
    for (int i = K; i < N; i++){
      A[i] = INF;
    }
  } else {
    for (int i = 0; i < K; i++){
      A[i] = S;
    }
    for (int i = K; i < N; i++){
      A[i] = 1;
    }
  }
  for (int i = 0; i < N; i++){
    cout << A[i];
    if (i < N - 1){
      cout << ' ';
    }
  }
  cout << endl;
}