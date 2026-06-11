#include <iostream>
#include <string>

using namespace std;

int const NMAX = 1e5;
int v[1 + NMAX];

int main() {

  int n, pos = 1, p, ans = 1;
  string GUIDO;
  cin >> n >> p;
  for(int i = max(p - n + 1, -1000000);i <= min(p + n - 1, 1000000);i++){
    cout << i << ' ';
  }
  return 0;
}
