#include <iostream>
using namespace std;

int main() {
  int d;
  while(cin >> d) {
    int sum = 0;
    int n = 1;
    while(n * d < 600) {
      sum += n*d * n*d * d;
      n++;
    }
    cout << sum << endl;
  }
}