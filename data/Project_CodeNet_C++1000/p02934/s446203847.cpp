#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<double> ai(n);
  for (int i = 0; i < n; i++) {
    cin >> ai.at(i);
  }
  
  double denomi = 0;
  for (double a : ai) {
    denomi += 1.0/a;
  }
  cout << 1.0/denomi << endl;
}