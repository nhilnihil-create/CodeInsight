#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long LL;

int main() {
  int N; cin >> N;
  int d = N % 10;
  if (d == 3) cout << "bon" << endl;
  else if (d == 0 || d == 1 || d == 6 | d == 8) cout << "pon" << endl;
  else  cout << "hon" << endl;
}
