#include <iostream>

using namespace std;

int const INF = 1e9;

int main() {

  int n, old = INF, b, pol = 0;
  cin >> n;
  for(int i = 1;i < n;i++){
    cin >> b;
    pol += min(old, b);
    old = b;
  }
  b = INF;
  pol += min(old, b);
  cout << pol;
  return 0;
}
