#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
const double PI = 3.14159265358979323846;

int main() {
  int n;
  cin >> n;
  vector<int> w(n);
  int cmp_minimum = 1e8;
  int sum = 0;
  rep(i, n) {
    cin >> w[i];
    sum += w[i];
  }
  int s1 = 0;
  int s2 = sum;
  rep(i, n-1) {
    s1 += w[i];
    s2 -= w[i];
    cmp_minimum = min(abs(s2-s1), cmp_minimum);
  }
  
  cout << cmp_minimum << endl;
  return 0;
}
