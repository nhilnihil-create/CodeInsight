#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  string S;
  int N, a, b;
  cin >> S;
  N=S.size();
  a=0;
  b=0;
  vector<string> T(N);
  vector<string> U(N);
  for (int i=0; i<N; i++) {
    T[i]=S.at(i);
    U[i]=S.at(N-1-i);
  }
  for (int j=0; j<N; j++) {
    if (T[j]==U[j]) {
      a=a+1;
    }
  }
  vector<string> V((N-1)/2);
  for (int k=0; k<(N-1)/2; k++) {
    V[k]=S.at((N-3)/2-k);
  }
  for (int l=0; l<(N-1)/2; l++) {
    if (T[l]==V[l]) {
      b=b+1;
    }
  }
  if (a==N && b==(N-1)/2) {
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }
}
