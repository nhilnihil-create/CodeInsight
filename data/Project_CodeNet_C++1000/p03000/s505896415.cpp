#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  long long X;
  cin >> N >> X;
  long long res = 1;
  long long S = 0;
  for (int i = 0; i < N; ++i) {
    long long v;
    cin >> v;
    S += v;
    if (S <= X) ++res;
  }
  cout << res << endl;
}