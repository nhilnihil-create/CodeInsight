#include <bits/stdc++.h>
using namespace std;
int main(){
  string S;
  cin >> S;
  int N = S.size();
  vector<string> T;
  T.push_back("");
  T[0].push_back(S[0]);
  T.push_back("");
  for (int i = 1; i < N; i++){
    T.back().push_back(S[i]);
    if (T[T.size() - 2] != T[T.size() - 1]){
      T.push_back("");
    }
  }
  if (T.back() == ""){
    T.pop_back();
  }
  if (T.size() >= 2){
    if (T[T.size() - 2] == T[T.size() - 1]){
      T.pop_back();
    }
  }
  cout << T.size() << endl;
}