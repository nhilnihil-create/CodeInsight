#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<double> v(n);
  for (int i = 0;i < n;i++){
    cin >> v[i];
  }
  
  sort(v.begin(), v.end());
  
  for (int i = 1;i < n;i++){
    v[i] = (v[i-1] + v[i])/2;
  }
  
  cout << fixed << setprecision(10);
  cout << v[n-1] << endl;
}