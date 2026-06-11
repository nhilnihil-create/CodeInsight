#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;

  int h = 0;
  long long sum = 0;
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    
    if (a < h) sum += h - a;
    else h = a;
  }
  cout << sum << endl;
}
