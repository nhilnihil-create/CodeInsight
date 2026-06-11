#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  int N;
  string S, T;
  cin >> N >> S >> T;
  if (N==1) {
    cout << S.at(0) << T.at(0) << endl;
  }
  else {
    for (int i=0; i<N-1; i++) {
      cout << S.at(i) << T.at(i);
    }
    cout << S.at(N-1) << T.at(N-1) << endl;
  }
}
