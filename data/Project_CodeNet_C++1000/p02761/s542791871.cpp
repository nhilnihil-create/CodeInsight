#include <iostream>
using namespace std;

int main() {
  int N, M; cin >> N >> M;
  int s[M], c[M];
  for (int i = 0; i < M; i++) cin >> s[i] >> c[i];
  
  int ans[N];
  for (int i = 0; i < N; i++) ans[i] = 10;
  bool flag = false;
  for (int i = 0; i < N; i++){
    for (int j = 0; j < M; j++){
      if (s[j] - 1 == i){
        if (ans[i] == 10) ans[i] = c[j];
        else if (ans[i] != c[j]) flag = true;
      }
    }
    if (N != 1 && i == 0){
      if (ans[i] == 10) ans[i] = 1;
      else if (ans[i] == 0) flag = true;
    }
    else if (ans[i] == 10) ans[i] = 0;
  }
  
  if (flag == true) cout << -1 << endl;
  else if (N == 3) cout << ans[0] * 100 + ans[1] * 10 + ans[2] << endl;
  else if (N == 2) cout << ans[0] * 10 + ans[1] * 1 << endl;
  else if (N == 1) cout << ans[0] << endl;
}