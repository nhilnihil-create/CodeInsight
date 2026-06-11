#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  int tac = a/d + (a%d ? 1 : 0);
  int aoc = c/b + (c%b ? 1 : 0);
  cout << (tac >= aoc ? "Yes" : "No") << endl;
}
