#include <bits/stdc++.h>
using namespace std;

int main() {

  int N;
  cin >> N;

  vector<int> A(N + 1);

  for(int i = 0; i < N; i++){
    cin >> A[i];
  }

  A[N] = 0;

  long long kane = 1000;
  long long kabu = 0;

  for(int i = 0; i < N; i++){
    if(A[i] < A[i + 1]){
      if(kabu == 0){
        kabu = kane / A[i];
        kane = kane % A[i];
      }
    }else if(A[i] > A[i + 1]){
      kane += kabu * A[i];
      kabu = 0;
    }
  }
  cout << kane << endl;
}