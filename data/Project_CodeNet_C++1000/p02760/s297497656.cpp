#include<bits/stdc++.h>
using namespace std;

int main(void){
  int A[3][3];
  int N;
  int ans[3][3];
  bool bingo = false;
  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++){
      cin >> A[i][j];
    }
  }
  cin >> N;
  int b[N];
  for(int i = 0; i < N; i++){
    cin >> b[i];
  }
  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++){
      ans[i][j] = false;
    }
  }
  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++){
      for(int k = 0; k < N; k++){
	if(A[i][j] == b[k])
	  ans[i][j] = true;
      }
    }
  }
  for(int i = 0; i < 3; i++){
    if(ans[i][0] == 1 && ans[i][1] == 1 && ans[i][2] == 1)
      bingo = true;
  }
  for(int i = 0; i < 3; i++){
    if(ans[0][i] == 1 && ans[1][i] == 1 && ans[2][i] == 1)
      bingo = true;
  }
  if(ans[0][0] == 1 && ans[1][1] == 1 && ans[2][2] == 1) bingo = true;
  if(ans[0][2] == 1 && ans[1][1] == 1 && ans[2][0] == 1) bingo = true;
  if(bingo) cout << "Yes" << "\n";
  else cout << "No" << "\n";
  return 0;
}
