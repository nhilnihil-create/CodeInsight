#include<bits/stdc++.h>
using namespace std;

int main(){
  int A[4][4];
  int N, B[11];
  for(int i = 0; i < 3; i++)
    for(int j = 0; j < 3; j++)
      cin >> A[i][j];
  cin >> N;
  for(int i = 0; i < N; i++) cin >> B[i];
  
  for(int h = 0; h < N; h++){
    for(int i = 0; i < 3; i++)
      for(int j = 0; j < 3; j++)
        if(A[i][j] == B[h]) A[i][j] = -1;
  }
  bool ans = false;
  for(int i = 0; i < 3; i++){
    if(A[i][0] == -1 && A[i][1] == -1 && A[i][2] == -1) ans = true;
    if(A[0][i] == -1 && A[1][i] == -1 && A[2][i] == -1) ans = true;
  }
  if(A[0][0] == -1 && A[1][1] == -1 && A[2][2] == -1) ans = true;
  if(A[2][0] == -1 && A[1][1] == -1 && A[0][2] == -1) ans = true;
  
  if (ans) cout <<"Yes" << endl;
  else cout << "No" << endl;
}
