#include <bits/stdc++.h>
using namespace std;
int main() {
  int N;
  cin >> N;
  vector<int> u(N);
  for (int i = 0; i < N; i++) {cin >> u.at(i);}
  sort(u.begin(), u.end());
  double D = u.at(0);
  for (int i = 1; i < N; i++) {
    D += u.at(i);
    D /= 2.0;
  }
  cout << D << endl;
}