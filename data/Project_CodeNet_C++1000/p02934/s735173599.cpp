#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    double inv_sum = 0;
  	for (int i = 0; i < n; i++) {
      double x;
      cin >> x;
      inv_sum += 1./x;
    }
  	cout << 1./inv_sum;
}