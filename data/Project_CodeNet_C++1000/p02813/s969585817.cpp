#include <bits/stdc++.h>
using namespace std;

int kj(int m) {
  if(m == 0) return 0;
  else {
    int sum = 1;
    for(int i = 1;i <= m;i++) sum *= i;
    return sum;
  }
}
int nc(int n) {
  int p, s, x = 0;
  vector<int> v(n, 1);
  for(int i = 0;i < n;i++) {
    cin >> p;
    v[p-1] = 0;
    s = 0;
    for(int j = 0;j < p;j++) s += v[j];
    x += s * kj(n - i - 1);
  }
  return x;
}

int main() {
  int n;
  cin >> n;
  int a = nc(n), b = nc(n);
  cout << abs(a - b) << endl;
}