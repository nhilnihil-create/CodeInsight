#include <bits/stdc++.h>
using namespace std;

int main() {
  int64_t A, B, C, D;
  cin >> A >> B >> C >> D;
  A--;
  int64_t a = A - (A / C + A / D - A / lcm(C, D));
  int64_t b = B - (B / C + B / D - B / lcm(C, D)); 
  cout << b - a << endl;
}