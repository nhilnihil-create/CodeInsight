#include <bits/stdc++.h>
using namespace std;

int main() {
  char a, b, c, d;
  cin >> a >> b >> c >> d;
  cout << ((a == b || b == c || c == d) ? "Bad" : "Good") << endl;
}