#include <iostream>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <map>
#include <vector>
#include <iomanip>

using namespace std;

int main(void) {
  int N;
  cin >> N;
  vector<string> S;
  string s;
  int T[N];
  for (int i = 0; i < N; i++) {
    cin >> s >> T[i];
    S.push_back(s);
  }
  string X;
  cin >> X;
  int a = 0;
  int f = 0;
  for (int i = 0; i < N; i++) {
    if (S[i] == X) {
      f = 1;
      continue;
    }
    if (f == 1) {
      a += T[i];
    }
  }
  cout << a << endl;
  return 0;
}
