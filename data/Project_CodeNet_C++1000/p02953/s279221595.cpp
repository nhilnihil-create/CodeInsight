#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N, M, H;
  cin >> N;
  bool cond{true};
  while (cond && cin >> H) {
    M = max(M, H);
    cond &= (M - H <= 1);
  }
  cout << (cond ? "Yes" : "No") << endl;
}
