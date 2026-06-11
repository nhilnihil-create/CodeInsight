#include <bits/stdc++.h>
using namespace std;

int main(){
  string S;
  cin >> S;
  int N = S.size();
  
  for (int i = 0; i < (N - 1) / 2; i++){
    if (S[i] != S[(N - 1) / 2 - 1 - i]){
      cout << "No" << endl;
      return 0;
    }
  }
  //前半が回文かどうか
  
  for (int i = 0; i < (N - 1) / 2; i++){
    if (S[(N - 1) / 2 + 1 + i] != S[N - 1 - i]){
      cout << "No" << endl;
      return 0;
    }
  }
  //後半が回文かどうか
  
  string S2 = S;
  reverse(S.begin(), S.end());
  if (S2 != S){
    cout << "No" << endl;
    return 0;
  }
  
  cout << "Yes" << endl;
}
  
