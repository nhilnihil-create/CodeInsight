#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long LL;

int main() {
  string S; cin >> S;
  for (int i = 0; i < S.size() - 1; ++i) {
    if (S[i] == S[i + 1]) {
      cout << "Bad" << endl;
      return 0;
    }
  }
  cout << "Good" << endl;
}
