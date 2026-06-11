#include <bits/stdc++.h>
 using namespace std;
 
int main() {
 int P = -1, Q, count = 0;
 int A[21];
 int B[21];
 int C[21];
  int N;
  cin >> N;
  for(int i=1;i<=N;i++){
    cin >> A[i];
  }
  for(int i=1;i<=N;i++){
    cin >> B[i];
  }
  for(int i=1;i<N;i++){
    cin >> C[i];
  }
  
  for(int i=1;i<=N;i++){
    Q = A[i];
    count += B[Q];
    if(P == Q - 1){
      count += C[P];
    }
    P=Q;
  }
  cout << count;
  return 0;
}