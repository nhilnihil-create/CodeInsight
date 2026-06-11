#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  string S, T;
  cin >> S >> T;
  for (int i = 0; i < N; i++) {
    cout << S.at(i);
    cout << T.at(i);
  }
  cout << "\n";
}