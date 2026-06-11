#include <bits/stdc++.h>
using namespace std;

int main() {
  int K;
  cin >> K;
  string S;
  cin >> S;
  int kazu = S.size();
  for (int i = 0; i < min(kazu, K); i++) {
    cout << S.at(i);
  }
  if (K < S.size()) {
    cout << "...";
  }
  cout << endl;
  return 0;
}