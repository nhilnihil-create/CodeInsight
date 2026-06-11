#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long LL;

int main() {
  int A, B, C; cin >> A >> B >> C;
  cout << max(0, C - (A - B)) << endl;
}
