#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  string S;
  cin >> N >> S;
  int C = 0;
  for (int i = 0; i < S.size(); i++) {
    if (S.at(i) == 'R') {
      C++;
    }
  }
  int CL = 0;
  for (int i = 0; i < C; i++) {
    if (S.at(i) == 'R') {
      CL++;
    }
  }  
  cout << C - CL << endl;
}
