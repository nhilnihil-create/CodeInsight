#include <bits/stdc++.h>
using namespace std;
 
int main() {
  double n;
  cin >> n;
  vector<double> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a.at(i);
  }
  sort(a.begin(), a.end()); 
  double count = (a.at(0) + a.at(1)) / 2;
  if (n >= 2) {
  for (int i = 0; i < n; i++) {
    if (i > 1) {
    count = (count + a.at(i)) / 2;
    }
  }
  }
  cout << count << endl;
}