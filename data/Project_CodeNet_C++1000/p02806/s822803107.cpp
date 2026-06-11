#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<string> s(N);
  vector<int> t(N);
  for (int i = 0; i < N; i++) {
    cin >> s[i] >> t[i];
  }
  string X;
  cin >> X;

  int i = find(begin(s), end(s), X) - begin(s) + 1;
  cout << accumulate(begin(t) + i, end(t), 0) << endl;

  return 0;
}
