#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  double a;
  double sum = 0;
  for(int i=0; i<n; i++) {
    cin >> a;
    sum += 1/a;
  }
  cout << fixed << setprecision(15) << 1/sum << endl;
}