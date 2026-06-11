#include <bits/stdc++.h>
using namespace std;
int main() {
int N, M;
cin >> N >> M;  
int A[N][M] = {0};
int B[M][1] = {0}; 
int C[N][1] = {0}; 

for (int i = 0; i < N; i++){
  for (int j = 0; j < M; j++){
cin >> A[i][j]; 
}
}
for (int j = 0; j < M; j++){
cin >> B[j][0]; 
}
for(int i = 0; i < N; i++){
  int S = 0; 
  for(int j = 0; j < M; j++){
    S += A[i][j] * B[j][0]; 
}
  C[i][0] = S; 
}
for(int i = 0; i < N; i++){
  cout << C[i][0] << endl; 
}
}
