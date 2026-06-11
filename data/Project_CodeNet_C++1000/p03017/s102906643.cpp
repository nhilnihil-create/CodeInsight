#include <bits/stdc++.h>
using namespace std;
int main(){
  int N, A, B, C, D;
  cin >> N >> A >> B >> C >> D;
  A--;
  B--;
  C--;
  D--;
  string S;
  cin >> S;
  bool ok = true;
  for (int i = A + 1; i < B - 1; i++){
    if (S[i] == '#' && S[i + 1] == '#'){
      ok = false;
    }
  }
  for (int i = C + 1; i < D - 1; i++){
    if (S[i] == '#' && S[i + 1] == '#'){
      ok = false;
    }
  }
  if (!ok){
    cout << "No" << endl;
  } else {
    if (C < D){
      cout << "Yes" << endl;
    } else {
      ok = false;
      for (int i = B; i <= D; i++){
        if (S[i - 1] == '.' && S[i] == '.' && S[i + 1] == '.'){
          ok = true;
        }
      }
      if (ok){
        cout << "Yes" << endl;
      } else {
        cout << "No" << endl;
      }
    }
  }
}