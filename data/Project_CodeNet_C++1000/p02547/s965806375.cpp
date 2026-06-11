#include <iostream>
using namespace std;

int main() {
  int n, d_i1, d_i2, series = 0;
  cin >> n;
  for (int i = 0; (i < n) && (series != 3); ++i) {
    cin >> d_i1 >> d_i2; 
    series += (d_i1 == d_i2);
    if (d_i1 != d_i2)
      series = 0;
  }
  if (series == 3)
    cout << "Yes" << '\n';
  else
    cout << "No" << '\n';
}