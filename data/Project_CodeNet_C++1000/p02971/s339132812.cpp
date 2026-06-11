#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  long n;
  cin >> n;
  
  vector<long> a(n), b(n);
  for (int i=0; i<n; ++i) {
    cin >> a.at(i);
  }
  b=a;
  sort(a.begin(), a.end());
  
  for (long i=0; i<n; ++i) {
    if (b.at(i)==a.at(a.size()-1)) {
      cout << a.at(a.size()-2) << endl;
    } else {
      cout << a.at(a.size()-1) << endl;
    }
  }
  
  return 0;
}