#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<double> a(n);
  for (int i = 0;i < n;i++){
    cin >> a[i];
  }
  
  vector<double> b(n);
  for (int i = 0;i < n;i++){
    b[i] = 1/a[i];
  }
  double total;
  
  for (int i = 0;i < n;i++){
    total += b[i];
  }
  
  cout << fixed << setprecision(10);
  cout << 1/total << endl;
}