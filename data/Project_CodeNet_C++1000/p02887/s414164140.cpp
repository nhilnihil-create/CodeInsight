#include <bits/stdc++.h>
using namespace std;

int main() {
  int N; cin >> N;
  string S; cin >> S;
  int count =1;
  int sameColor =1;
  for (int i =0; i<N-1; i++) {
    if (S.at(i) != S.at(i+1)) {
      if (sameColor != 1) {
        count++;
        sameColor =1;
      } else {
        count++;
      }
    } else {
      sameColor++;
    }
  }
  cout << count << endl;
}