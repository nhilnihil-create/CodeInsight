#include <bits/stdc++.h>
using namespace std;
int main() {
  int N, O = 0;
  cin >> N;
  vector<int> p(N);
  for (int i = 0; i < N; i++) {cin >> p.at(i);}
  for (int i = 0; i < N; i++) {
    if (i + 1 != p.at(i)) {O++;}
  }
  if (O == 2 || O == 0) {cout << "YES" << endl;}
  else {cout << "NO" << endl;}
}
