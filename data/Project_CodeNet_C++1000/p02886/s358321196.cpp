#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  long long a = 0, b = 0;
  for (int i = 0; i < N; ++i) {
    long long x; cin >> x;
    a += x * x;
    b += x;
  }
  cout << (b*b - a) / 2 << endl;
}
  
  
  
  