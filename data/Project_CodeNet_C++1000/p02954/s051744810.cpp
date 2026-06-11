#include <iostream>
#include <vector>

using namespace std;

int main() {
  string S;
  cin >> S;
  int n = S.size(), l{}, r{};
  vector<int> C(n);
  for (int i = 0; i != n; ++i) {
    if (S[n-i-1] == 'L') ++l;
    else {
      C[n-i] += l - l / 2;
      C[n-i-1] += l / 2;
      l = 0;
    }
    if (S[i] == 'R') ++r;
    else {
      C[i - 1] += r - r / 2;
      C[i] += r / 2;
      r = 0;
    } 
  }

  for (int i = 0; i != n; ++i) cout << (i?" " : "") << C[i];
  cout << endl;
}
