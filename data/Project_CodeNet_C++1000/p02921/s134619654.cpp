#include <iostream>

using namespace std;
using ll = long long;
using ld = long double;

void solve(string S, string T) {
  int cnt{};

  for(auto i = 0; i!=3; ++i) {
    if (S[i] == T[i]) ++cnt;
  }
  cout << cnt << endl;
}

int main() {
  string S;
  cin >> S;
  string T;
  cin >> T;
  solve(S, T);
  return 0;
}
