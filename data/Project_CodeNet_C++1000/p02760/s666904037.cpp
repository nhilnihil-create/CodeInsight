#include <iostream>
using namespace std;

int main() {
  int A[9];
  for (int i = 0; i < 9; i++) cin >> A[i];
  int N; cin >> N;
  int b[N];
  for (int i = 0; i < N; i++) cin >> b[i];
  
  bool flag[9];
  for (int i = 0; i < 9; i++) flag[i] = false;
  for (int i = 0; i < N; i++){
    for (int j = 0; j < 9; j++){
      if (b[i] == A[j]) flag[j] = true;
    }
  }
  bool ans = false;
  if (flag[0] + flag[1] + flag[2] == 3) ans = true;
  if (flag[3] + flag[4] + flag[5] == 3) ans = true;
  if (flag[6] + flag[7] + flag[8] == 3) ans = true;
  if (flag[0] + flag[3] + flag[6] == 3) ans = true;
  if (flag[1] + flag[4] + flag[7] == 3) ans = true;
  if (flag[2] + flag[5] + flag[8] == 3) ans = true;
  if (flag[0] + flag[4] + flag[8] == 3) ans = true;
  if (flag[2] + flag[4] + flag[6] == 3) ans = true;
  if (ans == true) cout << "Yes" << endl;
  else cout << "No" << endl;
}