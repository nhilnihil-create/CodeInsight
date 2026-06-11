#include <iostream>
#include <vector>
using namespace std;

int main() {
  long long n, price = 1000; cin >> n;
  vector<long long> a(n); for(int i = 0; i < n; i++) cin >> a[i];
  for(int i = 0; i < n-1; i++) {
    long long stocks = 0;
    if(a[i] < a[i+1]) stocks = price / a[i];
    price += (a[i+1] - a[i]) * stocks;
  }
  cout << price << endl;
  return 0;
}
