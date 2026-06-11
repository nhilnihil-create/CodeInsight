#include <bits/stdc++.h>
using namespace std;

int main() {
  int64_t A, Bl, Br;
  char dot;
  cin >> A;
  cin >> Bl >> dot >> Br;
  int64_t result;
  result = A * (Bl * 100 + Br);
  result /= 100;
  cout << result << endl;
  return 0;
}