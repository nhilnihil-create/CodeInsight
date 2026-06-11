#include <bits/stdc++.h>
using namespace std;
 
int main() {
 
  int N;
  cin >> N;
  
  int A[N];
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  
  int64_t count = 0;
  
  for (int i = 1; i < N; i++) {
    if(A[i-1] > A[i]){
      count += A[i-1] - A[i];
      A[i] = A[i-1];
    }
  }
  
  cout << count << endl;

}