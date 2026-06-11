#include <bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++){
    cin >> A[i];
  }
  sort(A.begin(), A.end());
  if (A[0] >= 0){
    int M = 0;
    for (int i = 1; i < N; i++){
      M += A[i];
    }
    M -= A[0];
    cout << M << endl;
    for (int i = 0; i < N - 2; i++){
      cout << A[0] << ' ' << A[i + 2] << endl;
      A[0] -= A[i + 2];
    }
    cout << A[1] << ' ' << A[0] << endl;
  } else if (A[N - 1] <= 0){
    int M = A[N - 1];
    for (int i = 0; i < N - 1; i++){
      M -= A[i];
    }
    cout << M << endl;
    for (int i = 0; i < N - 1; i++){
      cout << A[N - 1] << ' ' << A[i] << endl;
      A[N - 1] -= A[i];
    }
  } else {
    int M = 0;
    for (int i = 0; i < N; i++){
      M += abs(A[i]);
    }
    cout << M << endl;
    int p = upper_bound(A.begin(), A.end(), 0) - A.begin();
    for (int i = 0; i < p - 1; i++){
      cout << A[p] << ' ' << A[i] << endl;
      A[p] -= A[i];
    }
    for (int i = p + 1; i < N; i++){
      cout << A[p - 1] << ' ' << A[i] << endl;
      A[p - 1] -= A[i];
    }
    cout << A[p] << ' ' << A[p - 1] << endl;
  }
}