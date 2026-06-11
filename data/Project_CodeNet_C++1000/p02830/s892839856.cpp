#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  string S,T;
  cin >> S >> T;
  for(int j = 0; j < N; j++){
    cout << S.at(j) << T.at(j);
  }
  return 0;
}
