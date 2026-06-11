#include <bits/stdc++.h>
using namespace std;

int n, x[10], y[10];
double dist(int i, int j) {
  double dx = x[i] - x[j];
  double dy = y[i] - y[j];
  return sqrt(pow(dx, 2) + pow(dy, 2));
}

int main() {
  cin >> n;
  vector<int> v(n); 
  for (int i = 1; i <= n; i++) cin >> x[i] >> y[i];
  for(int i = 0; i < n; i++) v[i] = i + 1;
  double sum = 0.0;  
  do {
    for (int i = 0; i < n - 1; i++) {
      sum += dist(v[i], v[i+1]);
    }  
  } while(next_permutation(v.begin(), v.end()));
  int fac = 1;
  for (int i = 2; i <= n; i++) {
    fac *= i;
  }
  cout << fixed << setprecision(10) << sum /fac << endl;
}