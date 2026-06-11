#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;
  int N = S.size();
  
  for (int i = 0; i < N; i++) {
    if (S.at(i) != S.at(N-1-i)){
      cout << "No" << endl;
      return 0;
    }
  }
  for (int i = 0; i < (N-1)/2; i++) {
    if (S.at(i) != S.at((N-1)/2 -1-i)){
      cout << "No" << endl;
      return 0;
    }
  }
  for (int i = (N+3)/2; i < N; i++) {
    if (S.at(i) != S.at(N-1-i)){
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
}

