#include <bits/stdc++.h>
using namespace std;
int main() {
int N, M, L;
cin >> N >> M >> L;  
long long int A[N][M] = {0};
long long int B[M][L] = {0}; 
long long int C[N][L] = {0}; 

for (int i = 0; i < N; i++){
  for (int j = 0; j < M; j++){
cin >> A[i][j]; 
}
}
for (int i = 0; i < M; i++){
  for (int j = 0; j < L; j++){
cin >> B[i][j]; 
}
}
for(int i = 0; i < N; i++){
  for(int j = 0; j < L; j++){
      long long int S = 0; 
   for(int k = 0; k < M; k++){
    S += A[i][k] * B[k][j]; 
}
  C[i][j] = S; 
}
}
for(int i = 0; i < N; i++){
  for(int j = 0; j < L; j++){
  if(j == 0) cout << C[i][0]; 
  else cout << " " << C[i][j];    
}
cout << endl; 
}
}
