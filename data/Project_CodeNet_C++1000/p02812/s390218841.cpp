#include <iostream>
#include <string>
using namespace std;

int main() {
  int N;
  string S;
  cin >> N >> S;
  int res = 0;
  for (int i = 0; i + 2 < N; ++i) {
    if (S.substr(i, 3) == "ABC") ++res;
  }
  cout << res << endl;
}