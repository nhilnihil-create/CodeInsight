#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
#define FOR(i, a, b) for (int i=(a); i<(b); i++)

int main() {
  double N;
  cin >> N;
  int a = N/2;
  //cout << a << endl;
  cout <<  fixed << setprecision(7) << (N-a)/N << endl;
  return 0;
}