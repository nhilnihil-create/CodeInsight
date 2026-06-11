#include <bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin >> N;
  vector<string> U(N);
  for (int i = 0; i < N; i++){
    cin >> U[i];
  }
  bool lock = true;
  int M;
  cin >> M;
  for (int i = 0; i < M; i++){
    string T;
    cin >> T;
    bool ok = false;
    for (int j = 0; j < N; j++){
      if (T == U[j]){
        ok = true;
      }
    }
    if (ok){
      if (lock){
        cout << "Opened by " << T << endl;
        lock = false;
      } else {
        cout << "Closed by " << T << endl;
        lock = true;
      }
    } else {
      cout << "Unknown " << T << endl;
    }
  }
}
