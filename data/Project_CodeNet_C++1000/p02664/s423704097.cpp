#include <bits/stdc++.h>
using namespace std;

int main() {
  string T; cin >> T;
  int N = T.size();
  for(int i=0; i<N; i++) {
    if(T.at(i)=='?') T.at(i)='D';
    cout << T.at(i);
  }
  return 0;
}