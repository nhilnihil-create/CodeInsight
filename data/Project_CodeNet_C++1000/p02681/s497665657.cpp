#include<bits/stdc++.h>
using namespace std;

int main(){
  string S, T;
  int cnt = 0;
  cin >> S >> T;
  for (int i = 0; i < S.size(); i++){
    if (S[i] == T[i]) cnt++;
  }
  if (T[S.size()] >= 'a' && T[S.size()] <= 'z') cnt++;
  if (cnt == T.size()) cout << "Yes" << endl;
  else cout << "No" << endl;
}