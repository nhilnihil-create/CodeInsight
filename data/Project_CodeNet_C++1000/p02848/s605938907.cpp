#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  string S;
  cin >> S;
  for (int i = 0; i < S.size(); i++) {
    int tmp = S.at(i) - 'A';
    tmp += N;
    tmp %= 26;
    S.at(i) = char('A' + tmp);
  }
  cout << S << "\n";
}